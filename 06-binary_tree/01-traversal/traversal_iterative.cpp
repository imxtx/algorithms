#include <iostream>
#include <queue>
#include <stack>

#include "../utils.h"

using namespace std;

/**
 * @brief 先序遍历（非递归版本）
 *
 * @param root 根节点
 */
void preOrderIterative(treeNode *root)
{
    if (NULL == root) return;  // 空树

    stack<treeNode *> nodeStack;  // 创建一个栈保存节点
    nodeStack.push(root);         // 根节点进栈

    while (!nodeStack.empty())  // 栈非空时迭代处理
    {
        treeNode *node = nodeStack.top();  // 保存栈顶节点
        printf("%d ", node->data);         // 访问节点数据
        nodeStack.pop();                   // 栈顶节点出栈

        // 子节点入栈
        if (node->right) nodeStack.push(node->right);
        if (node->left) nodeStack.push(node->left);
    }
}

/**
 * @brief 中序遍历（非递归版本）
 *
 * @param root 根节点
 */
void inOrderIterative(treeNode *root)
{
    if (NULL == root) return;  // 空树

    stack<treeNode *> nodeStack;   // 创建一个栈保存节点
    treeNode *currentNode = root;  // 维护一个当前节点指针

    // 当前节点非空，或栈非空时迭代处理
    while (currentNode || !nodeStack.empty())
    {
        // 当前节点非空，沿着左子树方向入栈
        while (currentNode)
        {
            nodeStack.push(currentNode);
            currentNode = currentNode->left;
        }
        // 此时栈顶节点没有左子树，或已经访问完左子树
        currentNode = nodeStack.top();     // 取栈顶节点
        printf("%d ", currentNode->data);  // 访问节点数据
        nodeStack.pop();                   // 出栈
        currentNode = currentNode->right;  // 将当前节点设为右子节点
    }
}

/**
 * @brief 后序遍历（非递归版本）
 *
 * @param root 根节点
 */
void postOrderIterative(treeNode *root)
{
    if (NULL == root) return;  // 空树

    stack<treeNode *> nodeStack;   // 创建一个栈保存节点
    treeNode *currentNode = root;  // 维护一个当前节点指针
    treeNode *visitedNode = root;  // 保存上次一访问的节点, 初始化为root是利用二叉树是无环图

    // 当前节点非空，或栈非空时迭代处理
    while (currentNode || !nodeStack.empty())
    {
        // 当前节点非空，沿着左子树方向入栈
        while (currentNode)
        {
            nodeStack.push(currentNode);
            currentNode = currentNode->left;
        }
        currentNode = nodeStack.top();  // 取栈顶元素
        // 如果栈顶元素有右子树，且未被访问
        if (currentNode->right && currentNode->right != visitedNode)
        {
            currentNode = currentNode->right;
        }
        else  // 子树为空或被访问过
        {
            printf("%d ", currentNode->data);  // 访问节点数据
            visitedNode = currentNode;         // 记录当前访问的节点
            currentNode = NULL;                // 当前节点置为NULL，防止重复访问左子树
            nodeStack.pop();                   // 出栈
        }
    }
}

/**
 * @brief 层次遍历
 *
 * @param root
 */
void levelOrder(treeNode *root)
{
    if (NULL == root) return;  // 空树

    queue<treeNode *> nodeQueue;  // 创建一个队列保存节点
    nodeQueue.push(root);         // 将根节点入队

    // 队非空时进行访问
    while (!nodeQueue.empty())
    {
        treeNode *node = nodeQueue.front();            // 取头结点
        printf("%d ", node->data);                     // 访问节点数据
        if (node->left) nodeQueue.push(node->left);    // 左子节点入队
        if (node->right) nodeQueue.push(node->right);  // 右子节点入队
        nodeQueue.pop();                               // 头结点出队
    }
}

// 测试函数是否工作正常
void test()
{
    // 由数组创建二叉树, -1表示节点不存在
    int arr[] = {1, 2, 3, -1, 4, 5, 6, -1, -1, 7};
    // int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int len = NELEMS(arr);
    treeNode *root = createTreeFromArray(arr, len);

    // 测试4种遍历方法
    printf("先序：");
    preOrderIterative(root);
    putchar('\n');

    printf("中序：");
    inOrderIterative(root);
    putchar('\n');

    printf("后序：");
    postOrderIterative(root);
    putchar('\n');

    printf("层次：");
    levelOrder(root);
    putchar('\n');
}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}
