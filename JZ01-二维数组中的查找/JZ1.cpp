#include <iostream>
using namespace std;  
#include <vector>

class Solution {
	public:
	    bool Find(int target, vector<vector<int> > array) {
	        bool flag = false;
			int row = array.size();
	        int col = array[0].size();
	        for (int i = row-1 ; i >= 0 ; i--){
	        	for (int j = 0 ; j < col ; j++){
	        		if (array[i][j] > target){
	        			break;
					}else if (array[i][j] < target){
						continue;
					}else{
						flag = true;
						break;
					}
				}
				if(flag){
					break;
				} 
			}
			return flag; 
	    }
};

int main(){
	
	int a[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	vector<vector<int> > b(3,vector<int>(4,0));
	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 4 ; j++){
			b[i][j] = a[i][j];
		}
	}
	Solution s;
	cout<<s.Find(8,b);
	
	return 0;
} 
