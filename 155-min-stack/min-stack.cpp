class MinStack {
     vector<int> stack;
     vector<int> memory;
public:
    MinStack() {
         vector<int> stack;
     vector<int> memory;
    }
    
    void push(int value) {
        stack.push_back(value);
        if(memory.empty() || value <= memory.back()){
            memory.push_back(value);
        }
        else{
            memory.push_back(memory.back());
        }
    }
    
    void pop() {
        if(!stack.empty())
            stack.pop_back();
        memory.pop_back();    
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return memory.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */