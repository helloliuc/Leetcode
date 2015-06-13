class MinStack {
public:
    void push(int x) {
        nums.push(x);
        if(mins.empty()) mins.push(x);
        else mins.push(min(mins.top(), x));
    }

    void pop() {
        if(!nums.empty()) nums.pop(), mins.pop();
    }

    int top() {
        return nums.empty() ? 0 : nums.top();
    }

    int getMin() {
        return mins.empty() ? 0 : mins.top();
    }
private:
    stack<int> nums;
    stack<int> mins;
};
