// 用于计算数组的长度
#define NELEMS(x) (sizeof(x) / sizeof((x)[0]))

/**
 * @brief 二叉树的节点
 */
typedef struct treeNode
{
    int data;                // 数据
    struct treeNode *left;   // 左子节点
    struct treeNode *right;  // 右子节点
} treeNode;

// 由数组生成二叉树
treeNode *createTreeFromArray(int[], int);
// 创建节点
treeNode *createTreeNode(int);