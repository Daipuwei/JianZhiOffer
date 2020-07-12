#include <iostream>
using namespace std;

class Solution {
	public:
	    int jumpFloorII(int number) {
			long long fn = 1;
			if(number == 1){
				return 1;
			}
			for(int i = 2 ; i <= number ; i++){
				fn = fn << 1;
			}
			return fn;
	    }
};

int main(){
	int n;
	cin>>n;
	Solution s;
	cout<<s.jumpFloorII(n); 
	
	return 0;
} 
