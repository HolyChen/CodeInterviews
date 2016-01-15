/**
 * Question 7.1——用两个栈实现队列
 */

#include <iostream>
#include <stack>

using namespace std;

template <typename T> class CQueue {
public:
    CQueue() {}
    ~CQueue() {}

    void appendTail(const T& node) {
        stack1.push(node);
    }

    T deleteHead() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if (stack2.empty()) {
            throw exception("Warning: Queue is EMPTY");
        }

        T head = stack2.top();
        stack2.pop();

        return head;
    }
private:
    stack<T> stack1;
    stack<T> stack2;
};

int main() {
    CQueue<int> aQueue;
    aQueue.appendTail(1);
    aQueue.appendTail(2);
    aQueue.appendTail(3);
    cout << aQueue.deleteHead() << endl;

    aQueue.appendTail(4);
    cout << aQueue.deleteHead() << endl;
    cout << aQueue.deleteHead() << endl;
    cout << aQueue.deleteHead() << endl;

    try {
        aQueue.deleteHead();
    } catch (exception e) {
        cout << e.what() << endl;
    }
    return 0;
}