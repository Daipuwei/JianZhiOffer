#include <iostream>
#include <vector>
using namespace std; 

class Solution {
	public:
	    int minNumberInRotateArray(vector<int> rotateArray) {
	    	if (rotateArray.size() == 0){
	    		return 0;
			}
			int low = 0;
			int high = rotateArray.size() - 1;
			int mid = (low + high) / 2;
			while(rotateArray[low] >= rotateArray[high]){
				if(high - low ==1){
					mid = high;
					break;
				}
				mid = (low + high) / 2;
				if (rotateArray[low] == rotateArray[high] && rotateArray[low] == rotateArray[mid]){
					return this->findMin(rotateArray,low,high);
				}
				if (rotateArray[mid] >= rotateArray[low]){
					low = mid;
				}else if(rotateArray[mid] <= rotateArray[high]){
					high = mid;
				}
			}
			return rotateArray[mid];
	    }
	    
	    int findMin(vector<int> rotateArray,int low,int high){
	    	int min = rotateArray[low];
	    	for(int i = low + 1; i < high ; i++){
	    		if(rotateArray[i] < min){
	    			min = rotateArray[i];
				}
			}
			return min;
		}
};


int main(){
	
	int size;
	cin >> size;
	vector<int> array(size);
	for(int i = 0 ; i < size ; i++){
		cin>>array[i];
	}
	
	Solution s;
	cout<<s.minNumberInRotateArray(array);
	
	return 0;
}
