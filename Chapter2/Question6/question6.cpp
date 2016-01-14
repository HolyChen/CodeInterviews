/**
 * Question 6: 重建二叉树
 *
 * Description:
 * 输入某二叉树的前序遍历和中序遍历结果，请重建出该二叉树。假设输入的前序遍历
 * 和中序遍历的结果都不包含重复的数字。列入输入前序遍历序列{1, 2, 4, 7, 3, 5,
 * 6, 8}，和中序遍历序列{4, 7, 2, 1, 5, 3, 8, 6}，则重建出如下二叉树。
 * 并输出它后序遍历结果。
 *               1
 *              / \
 *             2   3
 *            /   / \
 *           4   5   6
 *            \     /
 *             7   8
 * Input:
 *    Line1: N -- 整数，二叉树中节点个数
 *    Line2: N个整数 -- 二叉树前序遍历结果，以空格分开
 *    Line3: N个整数 -- 二叉树中序遍历结果，以空格分开
 *
 * Output:
 *    Line1: N个整数 -- 二叉树后序遍历结果，以一个空格分割，结尾有换行，无空格
 *
 * Example：
 *    Input:
 *      8
 *      1 2 4 7 3 5 6 8
 *      4 7 2 1 5 3 8 6
 *    Output:
 *      7 4 2 5 8 6 3 1
 */

#include <iostream>

// 数组最大长度
const int MAX_SIZE = 1000;

struct BinaryTreeNode {
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};


// 重构二叉树，将后序遍历结果保存到postOrder数组中
void reconstruct(int number, int* preOrder, int* midOrder, int* postOrder);

int main() {
    // 前序遍历的序列
    int preOrder[MAX_SIZE];
    // 中序遍历的序列
    int midOrder[MAX_SIZE];
    // 节点数
    int N = 0;

    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> preOrder[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> midOrder[i];
    }
    
    // 后序遍历序列，用于保存输出结果
    int postOrder[MAX_SIZE];

    // 重构二叉树，将后序遍历结果保存到postOrder数组中
    reconstruct(N, preOrder, midOrder, postOrder);

    if (N >= 1) {
        std::cout << postOrder[0];
    }
    for (int i = 1; i < N; i++) {
        std::cout << " " << postOrder[i];
    }
    if (N >= 1) {
        std::cout << std::endl;
    }

    return 0;
}

BinaryTreeNode* constructCore(int* preOrderStart, int* preOrderEnd, int* midOrderStart, int* midOrderEnd) {
    if (preOrderStart > preOrderEnd || midOrderStart > midOrderEnd) {
        return nullptr;
    }

    int length = preOrderEnd - preOrderStart + 1;

    // 当前子树的根节点
    BinaryTreeNode *root = new BinaryTreeNode();
    int value = preOrderStart[0];
    root->value = value;
    
    int rootLoc = 0;
    for (; rootLoc < length; rootLoc++) {
        // 找到根节点在中序遍历结果的位置
        if (midOrderStart[rootLoc] == value) {
            break;
        }
    }
    if (rootLoc > length) {
        throw std::string("Invalid");
    }

    // 中序遍历中，根节点左侧的部分为左子树，右侧为右子树
    // 前序遍历中，根节点右侧的N个节点为左子树，之后为右子树
    // N为左子树长度，即中序遍历根节点位置
    root->left = constructCore(preOrderStart + 1, preOrderStart + rootLoc,
                               midOrderStart, midOrderStart + rootLoc - 1);
    root->right = constructCore(preOrderStart + rootLoc + 1, preOrderEnd, midOrderStart + rootLoc + 1, midOrderEnd);
    
    return root;    
}

void clear(BinaryTreeNode* root) {
    if (root == nullptr) {
        return;
    }
    clear(root->left);
    clear(root->right);
    delete root;
}

void postOrderTravers(BinaryTreeNode* root, int* postOrder, int& index) {
    if (root == nullptr) {
        return;
    }
    postOrderTravers(root->left, postOrder, index);
    postOrderTravers(root->right, postOrder, index);
    postOrder[index] = root->value;
    index++;
}

void reconstruct(int number, int* preOrder, int* midOrder, int* postOrder) {
    if (number <= 0 || preOrder == nullptr || midOrder == nullptr || postOrder == nullptr) {
        return;
    }
    BinaryTreeNode *root = nullptr;
    try {
        root = constructCore(preOrder, preOrder + number - 1, midOrder, midOrder + number - 1);
    } catch (std::string) {
        clear(root);
        return;
    }   

    int start = 0;
    postOrderTravers(root, postOrder, start);

    clear(root);
}