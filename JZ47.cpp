#include <iostream>
using namespace std;

class Solution {
	public:
	    int Sum_Solution(int n) {
	    	bool x = n > 1 && (n += this->Sum_Solution(n-1)); 
	    	return n;
	    }
};

int main()
{
	int n;
	Solution s;
	while(cin>>n){
		cout<<s.Sum_Solution(n);
	}
	
	return 0;
 } 
