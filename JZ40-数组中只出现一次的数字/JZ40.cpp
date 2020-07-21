#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
	public:
	    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
	    	if(data.size() == 0){
	    		return;
			}
			map<int,int> hash_map;
			for(int i = 0 ; i < data.size() ; i++){
				hash_map[data[i]]++;		
			}
			map<int,int>::iterator it;
			int cnt = 0;
			for(it = hash_map.begin() ; it != hash_map.end() ; it++){
				if(it->second == 1){
					if(cnt == 0){
						*num1 = it->first;
					}else{
						*num2 = it->first;
					}
					cnt++;
				}
			} 
	    }
};

int main()
{
	int n;
	while(cin>>n){
		vector<int> data(n);
		for(int i= 0 ; i < n ; i++){
			cin>>data[i];
		}
		int num1,num2;
		Solution s;
		s.FindNumsAppearOnce(data,&num1,&num2);
		cout<<num1<<" "<<num2;
	}
	
	return 0;
}
