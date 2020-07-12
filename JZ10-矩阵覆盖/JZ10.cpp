#include <iostream>
using namespace std;

class Solution {
	public:
	    int rectCover(int number) {
	    	if(number == 0){
	    		return 0;
			}else if(number == 1){
				return 1;
			}else if(number == 2){
				return 2;
			}
			long long f1 = 1,f2 = 2,fn;
			for(int i = 3 ; i <= number ; i++){
				fn = f1 + f2;
				f1 = f2;
				f2 = fn; 
			}
			return fn;
	    }
};

int main(){
	int n;
	cin>>n;
	Solution s;
	cout<<s.rectCover(n);
	
	return 0;
} 
