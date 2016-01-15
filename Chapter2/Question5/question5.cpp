/**
 * Question 5——从尾到头打印链表
 */
#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int mKey = 0;
    ListNode *mNext = nullptr;
};

void print(ListNode *head) {
    stack<int> reverse;    

    while (head != nullptr) {
        reverse.push(head->mKey);
        head = head->mNext;
    }

    bool flag = false;
    
    if (!reverse.empty()) {
        cout << reverse.top();
        reverse.pop();
        flag = true;
    }
    while (!reverse.empty()) {
        cout << " " << reverse.top();
        reverse.pop();
    }
    if (flag) {
        cout << endl;
    }
}

int main() {
    ListNode head;
    int n;
    cin >> n;
    ListNode *last = &head;
    for (int i = 0; i < n; i++) {
        ListNode *newNode = new ListNode();
        cin >> newNode->mKey;
        last->mNext = newNode;
        last = newNode;
    }
    print(head.mNext);
}