#include "utils.h"

#include <stdlib.h>
#include <string.h>

/**
 * @brief 创建一个二叉树节点
 *
 * @param data 节点数据
 * @return treeNode* 节点指针
 */
treeNode* createTreeNode(int data)
{
    treeNode* node = (treeNode*)malloc(sizeof(treeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/**
 * @brief 由数组生成二叉树
 *
 * @param arr 二叉树的数组表示, 第一个元素为根节点, 负数表示节点不存在
 * @param len 数组长度
 * @return treeNode* 根节点的指针
 */
treeNode* createTreeFromArray(int arr[], int len)
{
    // 数组为空
    if (len < 1) return NULL;

    // 用指针数组保存每个节点的地址，初始化NULL
    treeNode** nodesArr = (treeNode**)malloc(sizeof(treeNode*) * len);
    memset(nodesArr, 0, sizeof(treeNode*) * len);

    // 分配根节点
    nodesArr[0] = createTreeNode(arr[0]);

    // 扫描数组创建整棵二叉树
    for (int i = 0; i < len; i++)
    {
        int leftIdx = 2 * i + 1;   // 当前节点的左孩子下标
        int rightIdx = 2 * i + 2;  // 当前节点的右孩子下标
        if (leftIdx < len && arr[leftIdx] >= 0)
        {
            nodesArr[leftIdx] = createTreeNode(arr[leftIdx]);  // 创建左孩子，并存入数据
            nodesArr[i]->left = nodesArr[leftIdx];             // 设置节点i的左孩子
        }
        if (rightIdx < len && arr[rightIdx] >= 0)
        {
            nodesArr[rightIdx] = createTreeNode(arr[rightIdx]);  // 创建右孩子，并存入数据
            nodesArr[i]->right = nodesArr[rightIdx];             //设置节点i的右孩子
        }
    }

    // 返回根节点
    return nodesArr[0];
}