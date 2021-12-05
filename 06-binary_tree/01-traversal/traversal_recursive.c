#include <stdio.h>

#include "../utils.h"

/**
 * @brief 先序遍历（递归版本）
 *
 * @param root 根节点
 */
void preOrderRecursive(treeNode *root)
{
    if (NULL == root) return;        // root不为NULL才继续访问
    printf("%d ", root->data);       // 对数据进行访问
    preOrderRecursive(root->left);   // 访问左子树
    preOrderRecursive(root->right);  // 访问右子树
}

/**
 * @brief 中序遍历（递归版本）
 *
 * @param root 根节点
 */
void inOrderRecursive(treeNode *root)
{
    if (NULL == root) return;       // root不为NULL才继续访问
    inOrderRecursive(root->left);   // 访问左子树
    printf("%d ", root->data);      // 对数据进行访问
    inOrderRecursive(root->right);  // 访问右子树
}

/**
 * @brief 后序遍历（递归版本）
 *
 * @param root 根节点
 */
void postOrderRecursive(treeNode *root)
{
    if (NULL == root) return;         // root不为NULL才继续访问
    postOrderRecursive(root->left);   // 访问左子树
    postOrderRecursive(root->right);  // 访问右子树
    printf("%d ", root->data);        // 对数据进行访问
}

// 测试函数是否工作正常
void test()
{
    // 由数组创建二叉树, -1表示节点不存在
    int arr[] = {1, 2, 3, -1, 4, 5, 6, -1, -1, 7};
    int len = NELEMS(arr);
    treeNode *root = createTreeFromArray(arr, len);

    // 测试三种遍历方法
    printf("先序：");
    preOrderRecursive(root);
    putchar('\n');

    printf("中序：");
    inOrderRecursive(root);
    putchar('\n');

    printf("后序：");
    postOrderRecursive(root);
    putchar('\n');
}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}
