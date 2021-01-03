/*
 * @Description: 实现链表
 * @Version: 1.0
 * @Autor: Tabbit
 * @Date: 2021-01-03 10:01:18
 * @LastEditors: Tabbit
 * @LastEditTime: 2021-01-03 23:18:15
 */
#include <stdio.h>
#include <stdlib.h>
#define OK 1;
#define Error -1;
typedef int status;


typedef struct ChainList{
    int data;
    struct ChainList *next;
}ChainList, * MyChain;

status initChainedList(MyChain L, int n){
    // L = (MyChain)malloc(sizeof(ChainList));
    printf("%p\n", L);
    for (int i=1; i<n; i++) {
        MyChain tmp = (MyChain)malloc(sizeof(ChainList));
        tmp->next = L->next;
        tmp->data = i;
        L->next = tmp;
        free(tmp);
    }
    printf("%d\n", L->next->data);
    return OK;
}

status main() {
    
    ChainList a;
    printf("%p\n", &a);
    initChainedList(&a, 10);
    printf("%d\n", a.next->data);
    return 1;
}


