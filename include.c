#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void dd(int b[])
{
    b[0] = 0;
}

int fabonaci(int num)
{
    if (num <= 1)
        return 1;
    else
        return num * fabonaci(num - 1);
}

double average(int num, ...)
{
    va_list valist;
    va_start(valist, num);
    double sum = 0;
    for (int i = 0; i < num; i++)
    {
        sum += va_arg(valist, int);
    }
    va_end(valist);
    return sum / num;
}

int main()
{
    enum day
    {
        monday = 1,
        tuesday = 2
    } workday;

    enum day weekend = monday;
    int *a = (int *)(malloc(20*sizeof(int)));
    printf("sizeof int %lu \n", sizeof(int));
    int ddd[] = {1,2,3};
    printf("sizeof int %lu \n", sizeof(ddd));
    for (int i = 0; i < 10; i++)
    {
        a[i] = i;
    }
    printf("sizeof int %lu \n", sizeof(a));
    dd(a);
    printf("%p", &a[0]);
    printf("%.2f", average(4, 1, 2, 3, 4));
    fprintf(stderr, "yes\n");
    printf("fabonaci:: %d\n", fabonaci(10));

    int *aa = (int *)malloc(20);
    aa[0] = 1;
    aa[2011] = 21;
    printf("aa: %d\n", aa[2011]);
    printf("%lu", sizeof(a)/sizeof(int));
    for (int i = 1; i < 20; i++)
    {
        printf("a: %d\n", a[i]);
    }
    printf("Hello %d World", workday);
}
