#ifndef DLIST_H_INCLUDED
#define DLIST_H_INCLUDED

#define ElemType  int

typedef struct Node{
    ElemType data;
    struct Node *next;
    struct Node *prio;
}Node, *PNode;


typedef struct List{
    PNode first;
    PNode last;
    int size;
}List;

void InitList(List *MyList);

void showmenu();

void push_back(List *list, ElemType item);
void push_front(List *list, ElemType item);
void pop_back(List *list);
void pop_front(List *list);
void show_list(List *list);
Node* find(List *list, ElemType key);
void delete_val(List *list, ElemType key);
void resever(List *list);
void clear(List *list);
void sort(List *list);
void insert(List *list, Node *pos, ElemType x);
Node *buyNode(ElemType x);


#endif // DLIST_H_INCLUDED
