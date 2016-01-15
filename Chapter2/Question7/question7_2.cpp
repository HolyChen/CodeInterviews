/**
 * Question 7.2——用两个队列实现栈
 */

#include <iostream>
#include <queue>

using namespace std;

template <typename T> class CStack {
public:
    CStack() {}
    ~CStack() {}

    void push(const T& node) {
        // queue1的最后一个元素始终为队尾
        queue1.push(node);
    }

    T pop() {
        // 如果queue1, queue2都为空，则抛异常
        if (queue1.empty() && queue2.empty()) {
            throw exception("Warning: Stack is EMPTY");
        }


        if (!queue1.empty()) {
            // 如果queue1不为空，将queue1的除最后一个元素外，都插入queue2
            // 这样queue1持有最后一个元素
            while (queue1.size() > 1) {
                queue2.push(queue1.front());
                queue1.pop();
            }
            // 出掉队尾
            T tail = queue1.front();
            queue1.pop();
            return tail;
        } else {
            // 如果queue1为空，将queue2的除最后一个元素外，都插入queue1
            while (queue2.size() > 1) {
                queue1.push(queue2.front());
                queue2.pop();
            }
            // 如果此时queue1依旧为空，说明没有元素，抛异常
            T tail = queue2.front();
            queue2.pop();
            return tail;
        }

    }
private:
    queue<T> queue1;
    queue<T> queue2;
};

int main() {
    CStack<int> aStack;
    aStack.push(1);
    aStack.push(2);
    aStack.push(3);
    // queue1中不为空，queue2为空，弹出
    cout << aStack.pop() << endl;
    // queue1中为空，queue不为空弹出
    cout << aStack.pop() << endl;

    // queue1中为空，queue2不为空，插入两个
    aStack.push(4);
    aStack.push(5);
    cout << aStack.pop() << endl;
    cout << aStack.pop() << endl;
    cout << aStack.pop() << endl;

    // 过载弹出
    try {
        cout << aStack.pop() << endl;
    } catch (exception e) {
        cout << e.what() << endl;
    }
    return 0;
}