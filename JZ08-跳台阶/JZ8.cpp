#include <iostream>
using namespace std;

class Solution {
	public:
		int jumpFloor(int number) {
			if(number == 1){
				return 1;
			}else{
				long long f1 = 1 , f2 = 1, fn = 0;
				for(int i = 2 ; i <= number ; i++){
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
	cout<<s.jumpFloor(n);
	
	return 0;
}
