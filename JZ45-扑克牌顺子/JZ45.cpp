#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	public:
	    bool IsContinuous(vector<int> numbers){
	    	int size = numbers.size();
			if(size <= 0){
				return false;
			}
			
			sort(numbers.begin(),numbers.end());
			int cnt0 = 0;					//大小王个数 
			for(int i= 0 ; i < size ; i++){
				if(numbers[i] == 0){
					cnt0++;
				}else{
					break;
				}
			}
			
			int dist = 0;
			bool flag = true; 
			for(int i = cnt0+1 ; i < size ; i++){
				if(numbers[i] == numbers[i-1]){
					return false;
				}else{
					dist += numbers[i] - numbers[i-1]-1;
				}
			}
			
			if(cnt0 < dist){  //大小王个数小于剩余数字之间间隔，则无法配对 
				flag = false;
			}
			return flag;
	    }
};

int main()
{
	int n;
	Solution s;
	while(cin>>n){
		vector<int> array(n);
		for(int i = 0 ; i < n ; i++){
			cin>>array[i];
		}
		cout<<s.IsContinuous(array);
	}
	
	return 0;
} 
