#include <iostream>
using namespace std;

class Solution {
	public:
	    int  NumberOf1(int n) {
	    	int cnt = 0;
			while(n){
				cnt++;
				n = n & (n-1);
			}
			return cnt;     
	    }
};

int main(){
	int n;
	cin>>n;
	Solution s;
	cout<<s.NumberOf1(n);
	
	return 0;
}
