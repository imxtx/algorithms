#include <stdio.h>
#include <stdlib.h>

// 树节点定义
typedef struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
} Node;

// 辅助函数：比大小
int max(int a, int b)
{
    return a > b ? a : b;
}

// 辅助函数：计算树的高度
int height(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

// 辅助函数：创建新节点
Node *newNode(int key)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 0;
    return node;
}

// 辅助函数：获得节点的平衡因子
int getBalanceFactor(Node *node)
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// 右旋
Node *rightRotate(Node *y)
{
    /* 树结构示意图：
                y
               / \
              x   O
             / \
            O   O
    */
    Node *x = y->left;
    Node *xr = x->right;
    // 旋转
    x->right = y;
    y->left = xr;
    // 更新节点的高度
    x->height = height(x);
    y->height = height(y);
    // 返回旋转后的根节点
    return x;
}

// 左旋
Node *leftRotate(Node *y)
{
    /* 树结构示意图：
                y
               / \
              O   x
                 / \
                O   O
    */
    Node *x = y->right;
    Node *xl = x->left;
    // 旋转
    x->left = y;
    y->right = xl;
    // 更新节点的高度
    x->height = height(x);
    y->height = height(y);
    // 返回旋转后的根节点
    return x;
}

/**
 * @brief 向以node为根节点的树中插入key
 *
 * @param node 根节点
 * @param key 插入值
 * @return Node* 插入后该树的新的根节点
 */
Node *insert(Node *node, int key)
{
    // 1. 按照BST的方法在叶节点上插入新值
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;  // 值已经存在

    // 2. 更新插入路径上每棵子树的高度
    node->height = height(node);

    // 3. 计算平衡因子，不平衡则需要调整
    int bf = getBalanceFactor(node);

    // LL型不平衡
    if (bf > 1 && key < node->left->key)
        return rightRotate(node);
    // RR型不平衡
    if (bf < -1 && key > node->right->key)
        return leftRotate(node);
    // LR型不平衡
    if (bf > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // RL型不平衡
    if (bf < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // 如果是平衡的直接返回根节点
    return node;
}

// 辅助函数：输出树的先序遍历
void preOrder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(int argc, char const *argv[])
{
    struct Node *root = NULL;

    /* 测试，最终树结构应该如下图所示：
            30
           /  \
         20   40
        /  \     \
       10  25    50
    */
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf(
        "Preorder traversal of the constructed AVL tree is \n");
    preOrder(root);
    putchar('\n');

    return 0;
}
