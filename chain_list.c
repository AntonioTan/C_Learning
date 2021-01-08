/*
 * @Description: 实现链表
 * @Version: 1.0
 * @Autor: Tabbit
 * @Date: 2021-01-03 10:01:18
 * @LastEditors: Tabbit
 * @LastEditTime: 2021-01-08 10:05:54
 */
#include <stdio.h>
#include <stdlib.h>
#define OK 1;
#define Error -1;
typedef int status;

typedef struct ChainList
{
    int data;
    struct ChainList *next;
} ChainList, *MyChain;

/**
 * @description: 初始化链表并分配空间 
 * @param {*}
 * @return {*}: 返回链表指针
 * @author: Tabbit
 */
MyChain initChainedList()
{
    MyChain p = (MyChain)malloc(sizeof(ChainList));
    p->next = NULL;
    return p;
}

status deleteChainedList(MyChain L, int e)
{
    MyChain p = L;
    MyChain q = L;
    while (p && p->data != e)
    {
        q = p;
        p = p->next;
    }
    if (!p)
        return Error;
    q->next = p->next;
    return OK;
}

/**
 * @description: 插入新的节点并让链表有序 * @param {MyChain} L：链表
 * @param {int} e: 新插入的节点的值
 * @return {*}
 * @author: Tabbit
 */
status insertSortedChainedList(MyChain L, int e)
{
    MyChain p = L;
    while (p->next && p->next->data < e)
    {
        p = p->next;
    }
    MyChain newNode = initChainedList();
    newNode->data = e;
    newNode->next = p->next;
    p->next = newNode;
    return OK;
}


/**
 * @description: 将两个有序链表合并到第三个链表中 
 * @param {MyChain} a: 需要合并的链表1
 * @param {MyChain} b: 需要合并的链表2
 * @param {MyChain} c: 需要将两个链表合成到第三个链表中
 * @return {*}
 * @author: Tabbit
 */
status mergeChainedLists(MyChain a, MyChain b, MyChain c)
{
    while (a->next && b->next)
    {
        c->next = initChainedList();
        if (a->next->data < b->next->data)
        {
            c->next->data = a->next->data;
            a = a->next;
        }
        else
        {
            c->next->data = b->next->data;
            b = b->next;
        }
        c = c->next;
    }
    if (a->next)
    {
        c->next = a->next; 
    }
    if (b->next){
        c->next = b->next;
    }
    return OK;
}

/**
 * @description: 向链表插入新的节点 
 * @param {MyChain} L 链表的指针
 * @param {int} loc 从1开始
 * @param {int} e 要插入的数
 * @return {*} 返回状态
 * @author: Tabbit
 */
status insertChainedList(MyChain L, int loc, int e)
{
    int count = 0;
    printf("L:%d\n", L->data);
    MyChain p = L;
    while (count < loc - 1 && p)
    {
        p = p->next;
        ++count;
    }
    if (count < loc - 1)
    {
        return Error;
    }
    else
    {
        MyChain newNode = initChainedList();
        printf("%d\n", p->data);
        newNode->data = e;
        newNode->next = p->next;
        p->next = newNode;
        printf("next:%d\n", newNode->data);
        // L = p;
        printf("*L: %p\n", L);
        return OK;
    }
}

void test(MyChain a)
{
    MyChain b = (MyChain)malloc(sizeof(MyChain));
    b->data = 10;
    a = b;
    printf("%p\n", a);
}

status main()
{
    ChainList *t;
    printf("%p\n", t);
    test(t);
    printf("%p\n", t);

    ChainList *a;
    a = initChainedList();
    // printf("%p\n", a);
    // insertChainedList(a, 1, 2);
    // printf("%d\n", a->next->data);
    // insertChainedList(a, 2, 33);
    // printf("%d\n", a->next->data);
    // insertChainedList(a, 2, 43);
    // printf("%d\n", a->next->next->data);
    // deleteChainedList(a, 43);
    // printf("%d\n", a->next->next->data);
    printf("%p\n", a);
    insertSortedChainedList(a, 12);
    printf("%d\n", a->next->data);
    insertSortedChainedList(a, 2);
    printf("%d\n", a->next->data);
    insertSortedChainedList(a, 4);
    insertSortedChainedList(a, 4);
    printf("%d\n", a->next->next->data);
    deleteChainedList(a, 43);
    printf("%d\n", a->next->next->data);
    insertSortedChainedList(a, 0);
    printf("%d\n", a->next->data);

    MyChain b = initChainedList();
    MyChain c = initChainedList();
    insertSortedChainedList(b, 3);
    insertSortedChainedList(b, 1);
    insertSortedChainedList(b, 9);
    insertSortedChainedList(b, 7);
    mergeChainedLists(a, b, c);
    MyChain tmp_c = c;
    while(tmp_c->next) {
        printf("c: %d\n", tmp_c->next->data);
        tmp_c = tmp_c->next;
    }
    return 1;
}
