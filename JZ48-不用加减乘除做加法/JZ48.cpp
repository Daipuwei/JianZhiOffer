#include <iostream>
using namespace std; 

class Solution {
	public:
	    int Add(int num1, int num2){
	    	while(num2 != 0){
	    		int sum = num1^num2;
	    		int carry = (num1&num2)<<1;
	    		num2 = carry;
	    		num1 = sum;
			}
			return num1;
	    }
};

int main()
{
	int num1,num2;
	Solution s;
	while(cin>>num1>>num2){
		cout<<s.Add(num1,num2)<<endl;
	}
	
	
	return 0;
}
