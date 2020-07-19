#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
	public:
		int GetUglyNumber_Solution(int index) {
			if(index < 7) {
				return index;
			}
			vector<int> ans(index);
			ans[0] = 1;
			int t2 = 0,t3 = 0,t5 = 0;
			for(int i = 1 ; i < index ; i++) {
				ans[i] = min(ans[t2] * 2,min(ans[t3]*3,ans[t5] * 5));
				if(ans[t2] * 2 == ans[i]){
					t2++;	
				}
				if(ans[t3] * 3 == ans[i]){
					t3++;	
				}
				if(ans[t5] * 5 == ans[i]){
					t5++;	
				}
			}
			return ans[index-1];	
		}
};

int main() {
	int n;
	while(cin>>n) {
		Solution s;
		cout<<s.GetUglyNumber_Solution(n);
	}

	return 0;
}
