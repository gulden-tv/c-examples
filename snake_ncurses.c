/*
 * Для компиляции необходимо добавить ключ -lncurses
 * gcc -o prog main.c -lncurses
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <inttypes.h>

enum step {LEFT=1, UP, RIGHT, DOWN, STOP_GAME='q'};
enum {MAX_TAIL_SIZE=100, START_TAIL_SIZE=3, MAX_FOOD_SIZE=20, FOOD_EXPIRE_SECONDS=10};

struct tail {
    int x;
    int y;
} tail[MAX_TAIL_SIZE];

struct food {
    int x;
    int y;
    time_t put_time;
    char point;
    uint8_t enable;
} food[MAX_FOOD_SIZE];

struct snake {
    int x;
    int y;
    int direction;
    size_t tsize;
    struct tail *tail;
} snake;


void go(struct snake *current_p) {
    char ch[]="@";
    int max_x=0, max_y=0;
    getmaxyx(stdscr, max_y, max_x); // macro - размер терминала
    //clear(); // очищаем весь экран
    mvprintw(current_p->y, current_p->x, " "); // очищаем один символ
    switch (current_p->direction) {
        case LEFT:
            if(current_p->x <= 0) // Циклическое движение, что бы не
                                  // уходить за пределы экрана
                current_p->x = max_x;
            mvprintw(current_p->y, --(current_p->x), ch);
            break;
        case RIGHT:
            if(current_p->x >= max_x)
                current_p->x = 0;
            mvprintw(current_p->y, ++(current_p->x), ch);
            break;
        case UP:
            if(current_p->y <= 0)
                current_p->y = max_y;
            mvprintw(--(current_p->y), current_p->x, ch);
            break;
        case DOWN:
            if(current_p->y >= max_y)
                current_p->y = 0;
            mvprintw(++(current_p->y), current_p->x, ch);
            break;
        default:
            break;
    }
    refresh();
}
void changeDirection(int32_t *new_direction, int32_t key) {
    switch (key) {
        case KEY_DOWN: // стрелка вниз
            *new_direction = DOWN;
            break;
        case KEY_UP: // стрелка вверх
            *new_direction = UP;
            break;
        case KEY_LEFT: // стрелка влево
            *new_direction = LEFT;
            break;
        case KEY_RIGHT: // стрелка вправо
            *new_direction = RIGHT;
            break;
        default:
            break;
    }
}
void initTail(struct tail t[], size_t size) {
    struct tail init_t={0,0};
    for(size_t i=0; i<size; i++) {
        t[i]=init_t;
    }
}
void initHead(struct snake *head) {
    head->x = 0;
    head->y = 2;
    head->direction = RIGHT;
}
void initFood(struct food f[], size_t size) {
    struct food init = {0,0,0,0,0};
    int max_y=0, max_x=0;
    getmaxyx(stdscr, max_y, max_x);
    for(size_t i=0; i<size; i++) {
        f[i] = init;
    }
}
void init(struct snake *head, struct tail *tail, size_t size) {
    clear(); // очищаем весь экран
    initTail(tail, MAX_TAIL_SIZE);
    initHead(head);
    head->tail = tail; // прикрепляем к голове хвост
    head->tsize = size+1;
}
void goTail(struct snake *head) {
    char ch[] = "*";
    mvprintw(head->tail[head->tsize-1].y, head->tail[head->tsize-1].x, " ");
    for(size_t i = head->tsize-1; i>0; i--) {
        head->tail[i] = head->tail[i-1];
        if( head->tail[i].y || head->tail[i].x)
            mvprintw(head->tail[i].y, head->tail[i].x, ch);
    }
    head->tail[0].x = head->x;
    head->tail[0].y = head->y;
}
void addTail(struct snake *head) {
    if(head == NULL || head->tsize>MAX_TAIL_SIZE) {
        mvprintw(0, 0, "Can't add tail");
        return;
    }
    head->tsize++;
}
void printHelp(char *s) {
    mvprintw(0, 0, s);
}
void putFoodCeed(struct food *fp) {
    int max_x=0, max_y=0;
    char spoint[2] = {0};
    getmaxyx(stdscr, max_y, max_x);
    mvprintw(fp->y, fp->x, " ");
    fp->x = rand() % (max_x - 1);
    fp->y = rand() % (max_y - 2) + 1; //Не занимаем верхнюю строку
    fp->put_time = time(NULL);
    fp->point = '$';
    fp->enable = 1;
    spoint[0] = fp->point;
    mvprintw(fp->y, fp->x, spoint);
}
void putFood(struct food f[], size_t size) {
    int max_x=0, max_y=0;
    char spoint[2] = {0};
    getmaxyx(stdscr, max_y, max_x);
    for(size_t i=0; i<size; i++) {
        putFoodCeed(&f[i]);
    }
}
void refreshFood(struct food f[], int nfood) {
    int max_x=0, max_y=0;
    char spoint[2] = {0};
    getmaxyx(stdscr, max_y, max_x);
    for(size_t i=0; i<nfood; i++) {
        if( f[i].put_time ) {
            if( !f[i].enable || (time(NULL) - f[i].put_time) > FOOD_EXPIRE_SECONDS ) {
                putFoodCeed(&f[i]);
            }
        }
    }
}
_Bool haveEat(struct snake *head, struct food f[]) {
    for(size_t i=0; i<MAX_FOOD_SIZE; i++)
        if( f[i].enable && head->x == f[i].x && head->y == f[i].y  ) {
            f[i].enable = 0;
            return 1;
        }
    return 0;
}
void printLevel(struct snake *head) {
    int max_x=0, max_y=0;
    getmaxyx(stdscr, max_y, max_x);
    mvprintw(0, max_x-10, "LEVEL: %d", head->tsize);
}
void printExit(struct snake *head) {
    int max_x=0, max_y=0;
    getmaxyx(stdscr, max_y, max_x);
    mvprintw(max_y/2, max_x/2-20, "Your LEVEL is %d", head->tsize);
}
int main()
{
    char ch[]="*";
    int x=0, y=0, key_pressed=0;
    init(&snake, tail, START_TAIL_SIZE); //Инициализация, хвост = 3
    initFood(food, MAX_FOOD_SIZE);
    initscr();            // Старт curses mod
    keypad(stdscr, TRUE); // Включаем F1, F2, стрелки и т.д.

    raw();                // Откдючаем line buffering
    noecho();            // Отключаем echo() режим при вызове getch
    curs_set(FALSE);    //Отключаем курсор
    printHelp("  Use arrows for control. Press 'q' for EXIT");
    putFood(food, 3);// Кладем зерна
    timeout(0);    //Отключаем таймаут после нажатия клавиши в цикле
    while( key_pressed != STOP_GAME ) {
        key_pressed = getch(); // Считываем клавишу
        changeDirection(&snake.direction, key_pressed); // Меняем напарвление движения
        go(&snake); // Рисуем новую голову
        goTail(&snake); //Рисуем хвост
        if(haveEat(&snake, food)) {
            addTail(&snake);
            printLevel(&snake);
        }
        refreshFood(food, 3);// Обновляем еду
        timeout(100); // Задержка при отрисовке
    }
    printExit(&snake);
    timeout(20000);
    getch();
    endwin(); // Завершаем режим curses mod
    
    return 0;
}
