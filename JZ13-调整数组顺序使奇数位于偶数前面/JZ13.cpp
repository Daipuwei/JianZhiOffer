#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
	    void reOrderArray(vector<int> &array) {
	    	int size = array.size();
	    	int low = 0;
	    	int high = size - 1;
	    	while(low < high){
	    		while(low < high && !this->isEven(array[low])){	 	//从前到后找到偶数 
	    			low++;
				}
				while(low < high && this->isEven(array[high])){		//从后往前找奇数 
					high--;
				}
				if(low < high){
					array[low] += array[high];
					array[high] = array[low] - array[high];
					array[low] -= array[high];
				}
			}
	    }
	    
	    bool isEven(int n){
	    	return (n & 0x1) == 0;
		}
};

int main(){
	int n;
	while(cin>>n){
		vector<int> array(n);
		for(int i = 0 ; i < n ; i++){
			cin>>array[i];
		}
		Solution s;
		s.reOrderArray(array);
		for(int i = 0 ; i < array.size() ; i++){
			cout<<array[i]<<" ";
		}
	}
	
	return 0;
}
