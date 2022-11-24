
#include <ncurses.h>

int main()
{    int ch;
    
    initscr();            /* Start curses mode         */
    raw();                /* Line buffering disabled    */
    //noecho();            /* Don't echo() while we do getch */
    printw("Type text: \n");
    while( (ch = getch()) != '.')
    {
        printw("%c", ch);
    }
    
    //refresh();            /* Print it on to the real screen */
    getch();            /* Wait for user input */
    endwin();            /* End curses mode          */
    
    return 0;
}
