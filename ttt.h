#include <stdio.h>
/*
 * @Description: 测试外部链接
 * @Version: 1.0
 * @Autor: Tabbit
 * @Date: 2021-01-08 11:17:09
 * @LastEditors: Tabbit
 * @LastEditTime: 2021-01-08 11:34:45
 */

extern int ttt;
void test1() {
    printf("test1: %d\n", ttt);
}