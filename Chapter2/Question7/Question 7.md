## Question 7——栈与队列

### 7.1——用两个栈实现队列
#### Description:
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数appendTail和deleteHead，分别完成在队列尾部插入节点和在在队列头部删除节点的功能。
``` C++
template <typename T> class CQueue {
public:
    CQueue();
    ~CQueue();
    
    void appendTail(const T& node);
    T deleteHead();
private:
    stack<T> stack1;
    stack<T> stack2;
};
```

### 7.2——用两个队列实现栈
#### Description:
用两个队列实现一个栈，栈的声明如下，请实现它的两个函数push和pop，分别完成在栈顶压入节点和在栈顶弹出节点的功能
``` C++
template <typename T> class CStack {
public:
    CStack();
    ~CStack();
    
    void push(const T& node);
    T pop();
private:
    queue<T> queue1;
    queue<T> queue2;
};
```

