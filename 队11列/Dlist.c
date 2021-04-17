#include "Dlist.h"
#include <stdio.h>
#include <stdlib.h>

void InitList(List *MyList){

    Node *s = (Node *)malloc(sizeof(Node));
    MyList->first = MyList->last = s;
    MyList->last->next = NULL;
    MyList->last->prio = NULL;
    MyList->size = 0;
}

void showmenu(){
        printf("****************************************************\n");
        printf("*                                                  *\n");
        printf("*       [1]、push_back         [2]、push_fornt     *\n");
        printf("*       [3]、show_list         [4]、pop_back       *\n");
        printf("*       [5]、pop_fornt         [6]、insert_val     *\n");
        printf("*       [7]、find              [8]、length         *\n");
        printf("*       [9]、delete_val        [10]、sort          *\n");
        printf("*       [11]、resver           [12]、clear         *\n");
        printf("*       [13]、destory          [0]、quit_sytem     *\n");
        printf("*                                                  *\n");
        printf("****************************************************\n");
}

void push_back(List *list, ElemType item){
    Node *p = buyNode(item);
    p->next = list->last->next;
    p->prio = list->last;
    list->last->next = p;
    list->last = p;
    list->size++;
}

void show_list(List *list){
    Node* p = list->first->next;
    while(p){
        printf("%d-->", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

void push_front(List *list, ElemType item){
    Node *p = buyNode(item);
    if(list->size == 0){
        list->last = p;
    }else{
        p->next = list->first->next;
        p->next->prio = p;
    }
    list->first->next = p;
    p->prio = list->first;
    list->size++;
}


void pop_back(List *list){
    if(list->size == 0){
        return;
    }
    if(list->size == 1){
        free(list->last);
        list->last = list->first;
    }else{
        Node *p = list->first;
        while(p->next != list->last)
            p = p->next;
        free(list->last);
        list->last = p;
    }
    list->last->next = NULL;
    list->size--;
}


void pop_front(List *list){
    if(list->size == 0){
        return;
    }
    Node *p = list->first->next;
    if(list->first->next == list->last){
        list->last = list->first;
        list->last->next = NULL;
    }else{
        list->first->next = p->next;
        p->next->prio = list->first;
    }
    free(p);
    list->size--;
}

Node* find(List *list, ElemType key){
    Node *p = list->first->next;
    while(p != NULL&&p->data != key){
        p = p->next;
    }
    if(p == NULL)
        return NULL;
    return p;
}

void delete_val(List *list, ElemType key){
    if(list->size == 0){
        return;
    }
    Node *p = find(list, key);
    if(p == NULL){
        printf("链表中不存在%d\n", key);
        return;
    }
    if(p == list->last){
        list->last = p->prio;
        list->last->next = NULL;
    }else{
        p->next->prio = p->prio;
        p->prio->next = p->next;

    }
    free(p);
    list->size--;
}

void resever(List *list){


}

void clear(List *list){

}


void insert(List *list, Node *pos, ElemType x){

}


void sort(List *list){
    if(list->size == 1||list->size == 0){
        return;
    }
    Node *p = list->first->next;
    Node *q = p->next;
    list->last = p;
    list->last->next = NULL;
    while(q){
        p = q;
        q = q->next;

        Node *s = list->first;
        while(s->next != NULL &&s->next->data < p->data){
            s = s->next;
        }
        if(s->next == NULL){
            list->last->next = p;
            p->prio = list->last;
            list->last = p;
            list->last->next = NULL;
        }else{
            p·->next = s->next;
            s->next = p;
            p->prio = s;
            p->next->prio = p;
        }
    }
}

Node *buyNode(ElemType x){
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = x;
    p->next = p->prio = NULL;
    return p;

}
