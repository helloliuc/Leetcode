typedef struct Node{
    long x;
    Node *next;
    Node(long x, Node *next = NULL) {
        this->x = x;
        this->next = next;
    }
} Node;

class MinStack {
public:
    MinStack() {
        nums = NULL;
        minval = 0;
    }
    void push(int x) {
        if(nums == NULL) {
            nums = new Node(0);
            minval = x;
        }
        else {
            nums = new Node(x - minval, nums);
            if(x < minval) minval = x;
        }
    }

    void pop() {
        if(nums == NULL) return ;
        if(nums->x < 0) minval = minval - nums->x;
        
        Node *tmp = nums;
        nums = nums->next;
        delete tmp;
    }

    int top() {
        if(nums == NULL) return 0;
        else if(nums->x >= 0) return nums->x + minval;
        else return minval;
    }

    int getMin() {
        if(nums == NULL) return 0;
        else return minval;
    }
private:
    Node *nums;
    long minval;
};
