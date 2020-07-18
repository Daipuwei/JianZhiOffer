#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

struct cmp{
	bool operator ()(const int &a,const int &b){
		return a < b;
	}
};

class Solution {
	public:
	    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
	        int size = input.size();
	        if(size == 0 || k == 0 || k > size){
	        	vector<int> ans;
	        	return ans;
			}
			vector<int> ans(k);
			priority_queue<int,vector<int> ,cmp> q;
	        for(int i = 0 ; i < size ; i++){
	        	if(q.size() < k){
	        		q.push(input[i]);
				}else{
					if(input[i] < q.top()){
						//cout<<q.top()<<endl; 
						q.pop();
						q.push(input[i]);	
					}else{
						continue;
					}
				}
			}
			for(int i = 0 ; i < k ; i++){
				ans[i] = q.top();
				q.pop();
			}
			return ans;
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
