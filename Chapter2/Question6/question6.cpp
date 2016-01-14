/**
 * Question 6: �ؽ�������
 *
 * Description:
 * ����ĳ��������ǰ����������������������ؽ����ö����������������ǰ�����
 * ����������Ľ�����������ظ������֡���������ǰ���������{1, 2, 4, 7, 3, 5,
 * 6, 8}���������������{4, 7, 2, 1, 5, 3, 8, 6}�����ؽ������¶�������
 * �������������������
 *               1
 *              / \
 *             2   3
 *            /   / \
 *           4   5   6
 *            \     /
 *             7   8
 * Input:
 *    Line1: N -- �������������нڵ����
 *    Line2: N������ -- ������ǰ�����������Կո�ֿ�
 *    Line3: N������ -- �������������������Կո�ֿ�
 *
 * Output:
 *    Line1: N������ -- ��������������������һ���ո�ָ��β�л��У��޿ո�
 *
 * Example��
 *    Input:
 *      8
 *      1 2 4 7 3 5 6 8
 *      4 7 2 1 5 3 8 6
 *    Output:
 *      7 4 2 5 8 6 3 1
 */

#include <iostream>

// ������󳤶�
const int MAX_SIZE = 1000;

struct BinaryTreeNode {
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};


// �ع������������������������浽postOrder������
void reconstruct(int number, int* preOrder, int* midOrder, int* postOrder);

int main() {
    // ǰ�����������
    int preOrder[MAX_SIZE];
    // �������������
    int midOrder[MAX_SIZE];
    // �ڵ���
    int N = 0;

    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> preOrder[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> midOrder[i];
    }
    
    // ����������У����ڱ���������
    int postOrder[MAX_SIZE];

    // �ع������������������������浽postOrder������
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

    // ��ǰ�����ĸ��ڵ�
    BinaryTreeNode *root = new BinaryTreeNode();
    int value = preOrderStart[0];
    root->value = value;
    
    int rootLoc = 0;
    for (; rootLoc < length; rootLoc++) {
        // �ҵ����ڵ���������������λ��
        if (midOrderStart[rootLoc] == value) {
            break;
        }
    }
    if (rootLoc > length) {
        throw std::string("Invalid");
    }

    // ��������У����ڵ����Ĳ���Ϊ���������Ҳ�Ϊ������
    // ǰ������У����ڵ��Ҳ��N���ڵ�Ϊ��������֮��Ϊ������
    // NΪ���������ȣ�������������ڵ�λ��
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