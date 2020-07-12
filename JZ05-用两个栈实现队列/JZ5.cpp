#include <stack>

class Solution
{
	public:
	    void push(int node) {
	        this->stack1.push(node);
	    }
	
	    int pop() {
	        if(this->stack1.empty() && this->stack2.empty()){
	        	return 0;
			}
			if(this->stack2.empty()){
				while(!this->stack1.empty()){
					this->stack2.push(this->stack1.top());
					this->stack1.pop();
				}
			}
			int top = this->stack2.top();
			this->stack2.pop();
			return top;
	    }
	
	private:
	    stack<int> stack1;
	    stack<int> stack2;
};

int main(){
	
	return 0;
} 
