#include <iostream>
using namespace std;

class Solution {
	public:
		
		int Fibonacci(int n) {
			if(n == 0){
				return 0;
			}else if(n == 1){
				return 1;
			}else{
				long long f1 = 0 , f2 = 1, fn = 0;
				for(int i = 2 ; i <= n ; i++){
					fn = f1 + f2;
					f1 = f2;
					f2 = fn;
				}
				return fn;
			}
		}
};

int main()
{
	int n;
	cin>>n;
	
	Solution s;
	cout<<s.Fibonacci(n);
	
	return 0;
}
