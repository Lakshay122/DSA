class MinStack {
public:
    stack<long long> st;
    long long minVal;
    MinStack() {
        minVal=INT_MAX;
    }
    
    void push(int value) {
        if(st.empty()){
            st.push(value);
            minVal = value;
        }
        else if(value<minVal){
            st.push(2LL*value-minVal);
            minVal = value;
        }
        else {
            st.push(value);
        }
    }
    
    void pop() {
       long long top = st.top();
       st.pop();
       if(top<minVal){
            minVal = 2*minVal-top;
       }
      
    }
    
    int top() {
    long long top = st.top();
     
       if(top<minVal){
         return minVal;
       }
       return (int)top;
    }
    
    int getMin() {
        return (int)minVal;
        
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