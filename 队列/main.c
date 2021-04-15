#include <stdio.h>
#include <stdlib.h>
#include "Dlist.h"

int main()
{
    List MyList;
    InitList(&MyList);
    int select = 1;
    int item;
    int key;
    while(select){
        showmenu();
        printf("请选择：");
        scanf("%d", &select);
        if(select == 0){
            break;
        }
        switch(select){
        case 1:
            printf("请输入要插入的数据！(-1退出)");
            while(scanf("%d", &item), item != -1){
                push_back(&MyList, item);
            }
            break;
        case 2:
            printf("请输入要插入的数据！(-1退出)");
            while(scanf("%d", &item), item != -1){
                push_front(&MyList, item);
            }
            break;
        case 3:
            show_list(&MyList);
            break;
        case 4:
            pop_back(&MyList);
            break;
        case 5:
            pop_front(&MyList);
            break;
        case 8:
            printf("%d\n", MyList.size);
            break;
        case 9:
            printf("请输入要删除的值：");
            scanf("%d", &key);
            delete_val(&MyList, key);
            break;
        case 10:
            sort(&MyList);
            break;
        case 11:
            //resever(&MyList);
            break;
        case 12:
            //clear(&MyList);
            break;
        default:
            printf("输入错误，请重新输入！\n");
        }
    }
}
