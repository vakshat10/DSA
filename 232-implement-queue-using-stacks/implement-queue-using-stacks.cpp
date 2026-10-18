class MyQueue {
public:
    stack<int> s1, s2;

    MyQueue() {
    }

    // push: always into s1
    void push(int x) {
        s1.push(x);
    }

    // pop: remove and return the front of the queue
    int pop() {
        if (!s2.empty()) {
            // s2 has elements, its top is the oldest
            int val = s2.top();
            s2.pop();
            return val;
        }
        else {
            // s2 is empty, move everything from s1 to s2
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            int val = s2.top();
            s2.pop();
            return val;
        }
    }

    // top (peek): return the front of the queue without removing it
    int peek() {
        if (!s2.empty()) {
            return s2.top();
        }
        else {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};