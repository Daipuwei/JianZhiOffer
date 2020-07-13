#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
	    void reOrderArray(vector<int> &array) {
			int len = array.size();
			if(len == 0){
				return;
			}
	        vector<int> even;
	        vector<int> odd;
	        for(int i = 0 ; i < len ; i++){
	        	if(array[i] % 2 == 0){
	        		even.push_back(array[i]);
				}else{
					odd.push_back(array[i]);
				}
			}
			int cnt = 0; 
			for(int i = 0 ; i < odd.size() ; i++){
				array[cnt++] = odd[i];
			}
			for(int i = 0 ; i < even.size() ; i++){
				array[cnt++] = even[i];
			}
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
