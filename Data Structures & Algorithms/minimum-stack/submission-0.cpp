class MinStack {

private:
    stack<pair<int,int>> minStack;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        
        int currentMin = 0;

        if(minStack.empty()){
            currentMin = val;
        }else{
            currentMin = min(val, minStack.top().second);
        }

        minStack.push({val, currentMin});

    }
    
    void pop() {
        return minStack.pop();
    }
    
    int top() {
        return minStack.top().first;
    }
    
    int getMin() {
        return minStack.top().second;
    }
};
