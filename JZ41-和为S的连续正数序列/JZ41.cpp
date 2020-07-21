#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
	    vector<vector<int> > FindContinuousSequence(int sum) {
	    	vector<vector<int> > ans;
	    	if(sum <= 0){
	    		return ans;
			}
			int left = 1;
			int right = 1;
			int sumx = 1;
			while(left <= right){
				right++;
				sumx += right;
				while(sumx > sum){
					sumx -= left;
					left++;
				}
				if(sumx == sum && left != right){
					vector<int> data;
					for(int i = left ; i <= right ; i++){
						data.push_back(i);
					}
					ans.push_back(data);
				}
			}
			return ans; 
	    }
};

int main()
{
	int n;
	while(cin>>n){
		Solution s;
		vector<vector<int> > ans = s.FindContinuousSequence(n);
		for(int i = 0 ; i < ans.size() ; i++){
			vector<int> data = ans[i];
			for(int j = 0 ; j < data.size() ; j++){
				cout<<data[j]<<" ";
			}
			cout<<endl;
		}
	}
	
	return 0;
}
