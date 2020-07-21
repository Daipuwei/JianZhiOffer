#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
	    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
	    	vector<int> ans;
	    	if(array.size() == 0){
	    		return ans;
			}
			int i = 0, j = array.size()-1;
			int sumx = 0;
			while(i < j){
				sumx = array[i] + array[j];
				if(sumx < sum){
					i++;
				}else if(sumx > sum){
					j--;
				}else{
					ans.push_back(array[i]);
					ans.push_back(array[j]);
					break;
				}
			}
			return ans;
	    }
};

int main()
{
	int n,sum;
	while(cin>>n>>sum){
		vector<int> data(n);
		for(int i = 0 ; i < n ; i++){
			cin>>data[i];
		}
		Solution s;
		vector<int> ans;
		ans = s.FindNumbersWithSum(data,sum);
		for(int i = 0 ; i < ans.size() ; i++){
			cout<<ans[i]<<" ";
		}
	}
	
	
	return 0;
}
