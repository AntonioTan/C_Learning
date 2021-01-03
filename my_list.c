/*
 * 
 * 　　┏┓　　　┏┓+ +
 * 　┏┛┻━━━┛┻┓ + +
 * 　┃　　　　　　　┃ 　
 * 　┃　　　━　　　┃ ++ + + +
 *  ████━████ ┃+
 * 　┃　　　　　　　┃ +
 * 　┃　　　┻　　　┃
 * 　┃　　　　　　　┃ + +
 * 　┗━┓　　　┏━┛
 * 　　　┃　　　┃　　　　　　　　　　　
 * 　　　┃　　　┃ + + + +
 * 　　　┃　　　┃
 * 　　　┃　　　┃ +  神兽保佑
 * 　　　┃　　　┃    代码无bug　　
 * 　　　┃　　　┃　　+　　　　　　　　　
 * 　　　┃　 　　┗━━━┓ + +
 * 　　　┃ 　　　　　　　┣┓
 * 　　　┃ 　　　　　　　┏┛
 * 　　　┗┓┓┏━┳┓┏┛ + + + +
 * 　　　　┃┫┫　┃┫┫
 * 　　　　┗┻┛　┗┻┛+ + + +
 * 
 */

/*
 * @Description: 实现了线性表
 * @Version: 1.0
 * @Autor: Tabbit
 * @Date: 2020-12-31 22:42:27
 * @LastEditors: Tabbit
 * @LastEditTime: 2021-01-02 12:23:42
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Error -1;
#define OK 1;
typedef int status;

typedef struct My_list
{
    int *arr;
    int size;
    int length;
} My_list;

/**
 * @description:实现了初始化线性表 
 * @param {structMy_list} *my_list
 * @return {*}
 * @author: Tabbit
 */
status init_list(struct My_list *my_list)
{
    my_list->arr = (int *)malloc(sizeof(int) * 4);
    my_list->length = 0;
    my_list->size = 4 * sizeof(int);
    return OK;
}

status insert_list(struct My_list *my_list, int loc, int next)
{
    if (loc < 1 || loc > my_list->length + 1)
        return Error;

    if (my_list->size < (my_list->length + 1) * sizeof(int))
    {
        my_list->arr = (int *)realloc(my_list->arr, my_list->size * 2);
        my_list->size *= 2;
    }
    int *q = my_list->arr + loc - 1;
    for (int i = my_list->length - 1; i >= loc - 1; i--)
    {
        *(my_list->arr + i + 1) = *(my_list->arr + i);
    }
    *(my_list->arr + loc - 1) = next;
    my_list->length += 1;

    return OK;
}

status delete_list(struct My_list *my_list, int delEle)
{
    int count = 0; // 计数器
    while (count < my_list->length && *(my_list->arr + count) != delEle)
    {
        // 找到要删除的元素的位置
        ++count;
        printf("count %d\n", count);
    }
    if (count == my_list->length)
    {
        // 如果没有找到 返回Error
        return Error;
    }

    while (count < my_list->length-1)
    {
        *(my_list->arr + count) = *(my_list->arr + count + 1);
        ++ count;
    }
    // TODO 需要思考最后一个元素的释放问题
    *(my_list->arr + my_list->length) = NULL;
    --my_list->length;
    if (my_list->length / 2 * sizeof(int) < my_list->size && my_list->size > sizeof(int))
    {
        my_list->arr = (int *)realloc(my_list->arr, my_list->size / 2);
    }
    return OK;
}

int main()
{
    struct My_list testList;
    init_list(&testList);
    insert_list(&testList, 1, 22);
    insert_list(&testList, 1, 23);
    insert_list(&testList, 1, 44);
    insert_list(&testList, 1, 2333);
    insert_list(&testList, 1, 2);
    delete_list(&testList, 44);
    if (testList.arr)
        printf("Hello\n");
    printf("%d\n", testList.length);
    printf("%d\n", *(testList.arr + 3));
    int *a = (int *)malloc(sizeof(int) * 10);
    *a++ = 1;
    *a++ = 23;
    printf("%d\n", *(a - 2));
    return 0;
}