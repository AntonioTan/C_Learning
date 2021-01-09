/*
 * @Description: 实现树这一数据结构
 * @Version: 1.0
 * @Autor: Tabbit
 * @Date: 2021-01-09 21:16:28
 * @LastEditors: Tabbit
 * @LastEditTime: 2021-01-10 00:48:02
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define OK 1
#define Error -1
#define true 1
#define false 0
typedef int bool;
typedef int status;
typedef struct tree
{
    struct item *root;
    int size;
} tree, *my_tree;

typedef struct item
{
    struct item *left;
    struct item *right;
    int data;
} item, *my_item;


int max(const int a, const int b)
{
    if (a < b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

void InitializeItem(my_item pi, int num) {
    pi->data = num;
    pi->left = NULL;
    pi->right = NULL;
}

void InitializeTree(my_tree ptree)
{
    ptree->root = NULL;
    ptree->size = 0;
}

bool TreeIsEmpty(const my_tree ptree)
{
    if (ptree->root)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @description: 根据节点是否满判断这一层是否需要继续递归深入最终获取整个树的层数 
 * @param {constmy_item} item
 * @param {int} layer
 * @return {*}
 * @author: Tabbit
 */
int CheckItemFull(const my_item item, int layer)
{
    if (item->left && item->right)
    {
        return max(CheckItemFull(item->left, layer + 1), CheckItemFull(item->right, layer + 1));
    }
    else
    {
        return layer;
    }
}

/**
 * @description: 判断树是否满 
 * @param {constmy_tree} ptree
 * @return {*}
 * @author: Tabbit
 */
bool TreeIsFull(const my_tree ptree)
{
    int layerCount = 0;
    my_item root = ptree->root;
    int treeLayerCount = CheckItemFull(ptree->root, 0);
    /** 一颗满的树的项数应该等于（2^层数-1)*2+1 */
    if (ptree->size == (int)2 * (pow(2, treeLayerCount) - 1) + 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @description: 递归计算每一个节点及其子节点的数量 
 * @param {constmy_item} item
 * @return {*}
 * @author: Tabbit
 */
int ItemCount(const my_item item)
{
    int sum = 0;
    if (item)
    {
        sum += 1;
    }
    if (item->left)
    {
        sum += ItemCount(item->left);
    }
    if (item->right)
    {
        sum += ItemCount(item->right);
    }
    return sum;
}

int TreeItemCount(const my_tree ptree)
{
    if (ptree->root)
    {
        return ItemCount(ptree->root);
    }
    else
    {
        return 0;
    }
}

bool AddItemToItem(const my_item pi, my_item parentItem)
{
    if (pi->data < parentItem->data)
    {
        if (!parentItem->left)
        {
            parentItem->left = pi;
            return true;
        }
        else
        {
            return AddItemToItem(pi, parentItem->left);
        }
    }
    else if (pi->data == parentItem->data)
    {
        return false;
    }
    else
    {
        if (!parentItem->right)
        {
            parentItem->right = pi;
            return true;
        }
        else
        {
            return AddItemToItem(pi, parentItem->right);
        }
    }
}

bool AddItem(const my_item pi, my_tree ptree)
{
    if (!ptree->root)
    {
        ptree->root = pi;
        ptree->size += 1;
        return true;
    }
    else
    {
        bool result = AddItemToItem(pi, ptree->root);
        if(result) {
            ptree->size += 1;
        } 
        return result;
    }
}

bool InTree(const my_item pi, const my_tree ptree)
{
    return true;
}

bool DeleteItem(const my_item pi, my_tree ptree)
{
    return true;
}

void Traverse(const my_tree ptree, void (*pfun)(my_item))
{
}

void DeleteAll(my_tree ptree)
{
}

status main()
{
    my_tree tree = (my_tree)malloc(sizeof(tree));
    InitializeTree(tree);
    my_item item1 = (my_item)malloc(sizeof(item));
    InitializeItem(item1, 1);
    AddItem(item1, tree);
    my_item item2 = (my_item)malloc(sizeof(item));
    InitializeItem(item2, 3);
    AddItem(item2, tree);
    printf("size of tree is: %d", TreeItemCount(tree));

    return OK;
}
