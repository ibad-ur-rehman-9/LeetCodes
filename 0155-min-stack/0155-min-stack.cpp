class MinStack {
public:
    int size;
    int top_el;
    int* arr;
    MinStack(){
        size = 1000;
        top_el = -1;
        arr = new int[size];
    }
    MinStack(int size) : size(size) {
        arr = new int[size];
        top_el = -1;
    }
    
    void push(int val) {
        if((size - top_el )> 1)
        {
            ++top_el;
            arr[top_el] = val;
        }
        
    }
    
    void pop() {
        if(top_el >= 0)
        {
            --top_el;
        }
    }
    
    int top() {
        if(top_el>= 0 and top_el < size)
        {
            return arr[top_el];
        }
        return -1;
    }
    
    int getMin() {
        if(top_el>=0)
        {
            int minElement=pow(2,31)-1;
            MinStack temp(size);
            while(top_el!= -1)
            {
                if(arr[top_el] < minElement)
                {
                    minElement = arr[top_el];
                }
                temp.push(arr[top_el]);
                pop();
            }
            while(temp.top_el!=-1)
            {
                push(temp.top());
                temp.pop();
            }
            return minElement;
        }
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */