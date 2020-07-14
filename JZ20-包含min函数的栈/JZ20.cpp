#include <iostream>
#include <stack> 
using namespace std;


class Solution {
	stack<int> stk;
	stack<int> smin; 
	public:
	    void push(int value) {
	    	stk.push(value);
	    	if(smin.empty()){
	    		smin.push(value);
			}
	    	if(smin.top() > value){
	    		smin.push(value);
			}
	    }
	    
	    void pop() {
	        if(stk.top() == smin.top()){
	        	smin.pop();
			}
			stk.pop();
	    }
	    
	    int top() {
	    	return stk.top();
	    }
	    
	    int min() {
	        return smin.top();
	    }
};

int main()
{
	int n;
	while(cin>>n){
		Solution s; 
		int m;
		for(int i = 0 ; i < n ; i++){
			cin>>m;
			s.push(m);
		}
		cout<<s.min();
	} 
	
	
	return 0;
}
