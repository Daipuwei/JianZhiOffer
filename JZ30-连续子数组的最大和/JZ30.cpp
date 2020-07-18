#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
	    int FindGreatestSumOfSubArray(vector<int> array) {
	    	int max = 0xFFFFFFFF;
	    	int sum = 0;
	    	for(int i = 0 ; i < array.size() ; i++){
	    		sum += array[i];
	    		if(max < sum){
	    			max = sum;
				}else if(sum < 0){
					sum = 0; 
				}
			}
			return max;
	    }
};

int main()
{
	int n;
	while(cin>>n){
		vector<int> array(n);
		for(int i = 0 ; i < n ; i++){
			cin>>array[i];
		}
		Solution s;
		cout<<s.FindGreatestSumOfSubArray(array);
	}
	
	return 0;
}
