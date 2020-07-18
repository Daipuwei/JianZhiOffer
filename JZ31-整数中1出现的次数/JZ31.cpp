#include <iostream>
using namespace std;

class Solution {
	public:
	    int NumberOf1Between1AndN_Solution(int n){
			int m = n;
			int base = 1;
			int x;
			int ans = 0; 
			while(m){
				x = m % 10;
				m /= 10;
				ans += m*base;
				if(x == 1){
					ans += (n % base) + 1;
				}else if( x > 1){
					ans += base;
				}
				base *= 10;
			}
			return ans;
	    }
};

int main()
{
	int n;
	while(cin>>n){
		Solution s;
		cout<<s.NumberOf1Between1AndN_Solution(n);
	}
	
	return 0;
 } 
