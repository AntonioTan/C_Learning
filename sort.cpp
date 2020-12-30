/*
 * @Author: tabbit.tianyitan 
 * @Date: 2020-12-26 21:20:04 
 * @Last Modified by: tabbit.tianyitan
 * @Last Modified time: 2020-12-30 11:32:34
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void bubble_sort(int arr[], int size)
{
    /* 关于为什么这里需要传入arr的size 请参考这个链接
    https://stackoverflow.com/questions/25680014/find-the-size-of-integer-array-received-as-an-argument-to-a-function-in-c
     */
    bool change = true;
    for (int i = 0; i < size && change; i++)
    {
        change = false;
        for (int j = size - 1; j > i; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                change = true;
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}

void select_sort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void insert_sort(int arr[], int size)
{
    int arr2[size];
    memcpy(arr2, arr, sizeof(int) * size);
    for (int i = 1; i < size; i++)
    {
        int insertIndex = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
                insertIndex += 1;
        }
        if (insertIndex != i)
        {
            int tmp = arr[i];
            for (int j = i; j > insertIndex; j--)
            {
                arr[j] = arr[j - 1];
            }
            arr[insertIndex] = tmp;
        }
    }
}

void shell_sort(int arr[], int size)
{
    int groupSize = size;
    while (groupSize != 1)
    {
        groupSize = ceil(groupSize / 2);
        printf("%d\n", groupSize);
        for (int i = groupSize; i < size; i += 1)
        {
            for (int j = 0; j < i; j += groupSize)
            {
                printf("aarr %d %d\n", arr[j], arr[i]);
                if (arr[j] >= arr[i])
                {
                    printf("%d %d\n", j, i);
                    int tmp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = tmp;
                }
            }
        }
    }
}

int max(int left, int right)
{
    if (left < right)
    {
        return right;
    }
    else
    {
        return left;
    }
}

void merge_sort(int *left, int *right, int sizeLeft, int sizeRight)
{
    if (sizeLeft > 1)
    {
        int halfLeft = sizeLeft >> 1;
        merge_sort(left, left + halfLeft, halfLeft, sizeLeft - halfLeft);
    }
    if (sizeRight > 1)
    {
        int halfRight = sizeRight >> 1;
        merge_sort(right, right + halfRight, halfRight, sizeRight - halfRight);
    }
    int pLeft = 0;
    int pRight = 0;
    int arr[sizeLeft + sizeRight];
    int count = 0;
    while (pLeft < sizeLeft && pRight < sizeRight)
    {
        if (*left < *right)
        {
            arr[count] = *left;
            pLeft += 1;
            left += 1;
        }
        else
        {
            arr[count] = *right;
            pRight += 1;
            right += 1;
        }
        count += 1;
    }
    if (pLeft < sizeLeft)
    {
        for (int i = pLeft; i < sizeLeft; i++, count++)
        {
            arr[count] = *left;
            left += 1;
        }
    }
    if (pRight < sizeRight)
    {
        for (int i = pRight; i < sizeRight; i++, count++)
        {
            arr[count] = *right;
            right += 1;
        }
    }
    right -= sizeRight;
    left -= sizeLeft;

    for (int i = 0; i < sizeLeft; i++)
    {
        *left = arr[i];
        left += 1;
    }
    for (int i = sizeLeft; i < sizeRight + sizeLeft; i++)
    {
        *right = arr[i];
        right += 1;
    }
}

void quick_sort(int *arr, int size)
{
    if (size > 1)
    {
        int p = *arr;
        int i = 0;
        int j = size - 1;
        int count = 0;
        while (i != j)
        {
            while (i < j && *(arr + i) < p)
            {
                i++;
            }

            while (j > i && *(arr + j) > p)
            {
                j--;
            }
            /* 解决i和j两个指针虽然地址不同但值一样的情况 即可能陷入循环交换 */
            if (arr + i != arr + j && *(arr + i) == *(arr + j))
            {
                j--;
            }
            else
            {
                int tmp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = tmp;
            }
        }
        if (arr != arr + i)
        {
            // printf("%d\n", *(p + 1));
            quick_sort(arr, i);
            quick_sort(arr + i + 1, size - i - 1);
        }
    }
}

int main(int argv, char *argc[])
{
    int arr[] = {4, 99, 11, 42, 5, 2, 22, 11, 13};
    int size = sizeof(arr) / sizeof(int);
    quick_sort(&arr[0], size);
    // merge_sort(&arr[0], &arr[size >> 1], size >> 1, size - (size >> 1));
    for (int i = 0; i < size; i++)
    {
        printf("arr %d is: %d\n", i, arr[i]);
    }
    return 0;
}
