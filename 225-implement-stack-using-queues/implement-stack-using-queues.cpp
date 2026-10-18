class MyStack {
public:
    queue<int> q;

    MyStack() {
    }

    void push(int x) {
        q.push(x);                       // add new element at the back

        // move all older elements behind the new one
        int count = q.size() - 1;
        while (count--) {
            q.push(q.front());           // copy front to back
            q.pop();                     // remove it from the front
        }
    }

    int pop() {
        int val = q.front();             // front is the stack's top
        q.pop();
        return val;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};