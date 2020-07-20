#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
	    int GetNumberOfK(vector<int> data ,int k) {
			int size = data.size();
			if(size == 0){
				return 0;
			}
			
			if(size == 1 && data[0] == k){
				return 1;
			}else if(size == 1 && data[0] != k){
				return 0;
			}
			
			// 有序数组利用二分查找k在数组中的下表 
			int index = this->Find(data,k);
			
			// 若index为-1，则表示数组中不包括k 
			if(index == -1){
				return 0;
			}
			
			// 向左扫描查看是否有重复元素
			int cnt = 1;
			for(int i = index-1 ; i >= 0 ; i--){
				if(data[i] == k){
					cnt++;
				}else{
					break;
				}
			}
			// 向右扫描查看是否有重复元素
			for(int i = index+1 ; i < size ; i++){
				if(data[i] == k){
					cnt++;
				}else{
					break;
				}
			}
			return cnt;
	    }
	    
	    int Find(vector<int> data ,int k){
	    	int low = 0;
	    	int high = data.size() - 1;
	    	int mid;
	    	while(low <= high){
	    		mid = (low + high) / 2;
	    		if(data[mid] > k){
	    			high = mid - 1;
				}else if(data[mid] < k){
					low = mid + 1;
				}else{
					break;
				}
			}
			// 若是low与high相等了，仍未找到k则数组里没有k 
			if(data[mid] != k){
				mid = -1;
			}
			return mid;
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
		cout<<s.GetNumberOfK(array,k);
	}
	
	return 0;
}
