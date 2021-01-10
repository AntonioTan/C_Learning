/*
 * @Description: 实现树这一数据结构
 * @Version: 1.0
 * @Autor: Tabbit
 * @Date: 2021-01-09 21:16:28
 * @LastEditors: Tabbit
 * @LastEditTime: 2021-01-11 00:17:55
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
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

typedef struct pair
{
    struct item *parent;
    struct item *child;
} pair, *my_pair;

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

my_item InitializeItem(int num)
{
    my_item pi = (my_item)malloc(sizeof(item));
    pi->data = num;
    pi->left = NULL;
    pi->right = NULL;
    return pi;
}

my_pair InitializePair()
{
    my_pair pair = (my_pair)malloc(sizeof(pair));
    pair->child = NULL;
    pair->parent = NULL;
    return pair;
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

bool AddItem(const int pi, my_tree ptree)
{
    my_item newItem = InitializeItem(pi);
    if (!ptree->root)
    {
        ptree->root = newItem;
        ptree->size += 1;
        return true;
    }
    else
    {
        bool result = AddItemToItem(newItem, ptree->root);
        if (result)
        {
            ptree->size += 1;
        }
        return result;
    }
}

bool InTree(const int pi, const my_tree ptree)
{
    my_item target = ptree->root;
    while (true)
    {
        if (target->data == pi)
        {
            return true;
        }
        else
        {
            if (target->left || target->right)
            {
                if (pi < target->data)
                {
                    if (!target->left)
                    {
                        return false;
                    }
                    else
                    {
                        target = target->left;
                    }
                }
                else
                {
                    if (!target->right)
                    {
                        return false;
                    }
                    else
                    {
                        target = target->right;
                    }
                }
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

my_pair FindItem(const int pi, my_tree ptree)
{
    my_pair pair = InitializePair();
    pair->child = ptree->root;
    my_item target = ptree->root;
    while (true)
    {
        if (target->data == pi)
        {
            return pair;
        }
        else
        {
            if (pi < target->data)
            {
                if (target->left)
                {
                    pair->parent = target;
                    pair->child = target->left;
                    target = target->left;
                }
                else
                {
                    return NULL;
                }
            }
            else
            {
                if (target->right)
                {
                    pair->parent = target;
                    pair->child = target->right;
                    target = target->right;
                }
                else
                {
                    return NULL;
                }
            }
        }
    }
    return pair;
}

bool DeleteItem(const int pi, my_tree ptree)
{
    my_pair findPair = FindItem(pi, ptree);
    if (!findPair)
    {
        return false;
    }
    else if (!findPair->parent)
    {
        ptree->root = NULL;
        ptree->size --;
    }
    else
    {
        my_item parent = findPair->parent;
        my_item child = findPair->child;
        if (child->left && child->right)
        {
            my_item maxLeft = child->left;
            while(maxLeft->right) {
                maxLeft = maxLeft->right;
            }
            maxLeft->right = child->right;
            if (parent->left == child) {
                parent->left = child->left;
            } else {
                parent->right = child->right;
            }
        }
        else if (child->left)
        {
            if (parent->left == child)
            {
                parent->left = child->left;
            } else {
                parent->right = child->left;
            }

        }
        else if (child->right)
        {
            if (parent->left == child)
            {
                parent->left = child->right;
            }
            else
            {
                parent->right = child->right;
            }
        }
        else
        {
            if (parent->left == child)
            {
                parent->left = NULL;
            }
            else
            {
                parent->right = NULL;
            }
        }
        free(child);
    }
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
    AddItem(100, tree);
    AddItem(3, tree);
    for (int i = 0; i < 1000; i++)
    {
        // printf("%d\n", rand()*10);
        srand((unsigned)time(NULL) + i);
        AddItem(rand(), tree);
    }
    AddItem(1323, tree);
    printf("size of tree is: %d\n", TreeItemCount(tree));
    printf("item1 is in the tree: %d\n", InTree(1323, tree));
    DeleteItem(3, tree);
    my_pair rst = FindItem(1323, tree);
    if (rst)
    {
        printf("parent is: %d\nchild is %d\n", rst->parent->data, rst->child->data);
    }
    return OK;
}
