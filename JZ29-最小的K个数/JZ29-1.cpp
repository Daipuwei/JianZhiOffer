#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
	    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
	        int size = input.size();
	        if(size == 0 || k == 0 || k > size){
	        	vector<int> ans;
	        	return ans;
			}
			
			int low = 0,high = size-1;
			int pivot = Partition(input,low,high);
			while(pivot != k-1){
				if(pivot > k-1){
					high = pivot-1;
					pivot = Partition(input,low,high);
				}else{
					low = pivot + 1;
					pivot = Partition(input,low,high);
				}
			}
			
			vector<int> ans(k);
			for(int i = 0 ; i < k ; i++){
				ans[i] = input[i];
			}
			return ans;
	    }
	    
	    int Partition(vector<int> &input,int low,int high){
	    	int pivot = input[low];
	    	while(low < high){
	    		while(low < high && input[high] >= pivot){
	    			high--;
				}
				input[low] = input[high];
				while(low < high && input[low] <= pivot){
	    			low++;
				}
				input[high] = input[low];
			}
			input[low] = pivot;
			return low;
		}
};

int main()
{
	int n,k;
	while(cin>>n>>k){
		vector<int> array(n);
		for(int i = 0 ; i < n ; i++){
			cin>>array[i];
		}
		Solution s;
		vector<int> ans = s.GetLeastNumbers_Solution(array,k);
		for(int i = 0 ; i < k ; i++){
			cout<<ans[i]<<" ";
		}
	} 
	
	return 0;
}
