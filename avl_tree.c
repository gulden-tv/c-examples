#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct tree {
    int32_t key;
    struct tree *left, *right;
    struct tree *parent;
} tree;


void insert(tree **root,int key, tree *pt) {
    if(!(*root)) {
        *root=malloc(sizeof(tree));
        (*root)->key=key;
        (*root)->left=(*root)->right=NULL;
        (*root)->parent=pt;
    }
    else if( key < (*root)->key)
        insert( &((*root)->left) ,key,*root);
    else
        insert( &((*root)->right),key,*root);
}
void print_tree(tree *root) {
    if(root) {
        printf("%d ",root->key);
        if(root->left)
            print_tree(root->left);
        if(root->right)
            print_tree(root->right);
    }
}
/* Рекурсивная реализация */
tree* search_tree(tree *root, int32_t key) {
    if(root==NULL || root->key == key)
        return root;
    else if(root->key > key)
        return search_tree(root->left, key);
    else
        return search_tree(root->right, key);
}
/* Итеративная версия */
tree* search_tree_i(tree *root, int32_t key) {
    tree *find=root;
    while(find && find->key!=key) {
        if( key < find->key )
            find = find->left;
        else
            find = find->right;
    }
    return find;
}
tree* min_tree(tree *root) {
    tree *find=root;
    while(find && find->left) {
            find = find->left;
    }
    return find;
}
tree* max_tree(tree *root) {
    tree *find=root;
    while(find && find->right) {
            find = find->right;
    }
    return find;
}
tree* left_follower(tree *root) {
    if(root==NULL)
        return root;
    if(root->right)
        return min_tree(root->right);
    else {
        tree *y = root->parent;
        tree *x = root;
        while(y && x==y->right) {
            x = y;
            y = y->parent;
        }
        return y;
    }
}
/*  Удаление узла из дерева */
tree* delete(tree *root, tree* pt) {
    tree *remove = NULL, *remove_son;
    /*Нет потомков или один потомок. Удаляем сам узел */
    if(pt->left == NULL || pt->right == NULL)
        remove = pt;
    else
    /* Два потомка. Удаляем его последователя.
     У последователя только один правый потомок,
     потому что это самый левый элемент правого
     поддерева.
     */
        remove = left_follower(pt);// Всегда только один потомок
    
    /* Прикрепляем потомка удаляемого элемента к родителю, либо делаем этого потомка корнем дерева*/
    if(remove->left!=NULL) // не сработает если это последователь pt
        remove_son = remove->left;
    else
        remove_son = remove->right;
    if( remove_son ) // обновляем родителя у удаляемого потомка
        remove_son->parent = remove->parent;
    if(remove->parent==NULL) // если удаляем корень
        root = remove_son;
    else if (remove == remove->parent->left)
        remove->parent->left = remove_son;
    else
        remove->parent->right = remove_son;
    if(pt != remove)
        pt->key = remove->key;
    return remove;
}



int main(int argc, const char * argv[]) {
    tree *tr=NULL;

    insert(&tr,44,NULL);
    insert(&tr,36,NULL);
    insert(&tr,83,NULL);
    insert(&tr,31,NULL);
    insert(&tr,42,NULL);
    insert(&tr,48,NULL);
    insert(&tr,89,NULL);
    insert(&tr,30,NULL);
    insert(&tr,45,NULL);
    insert(&tr,64,NULL);

    print_tree(tr);
    tree *find = search_tree(tr, 83);
    tree *fordel = delete(tr, find);
    free(fordel);
    //printf("Find %d\n",(find)?find->key:0 );
    printf("\n");
    print_tree(tr);
    return 0;
}
