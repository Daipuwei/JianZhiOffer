#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
	public:
	    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
			if(pushV.size() == 0 || popV.size() == 0){
				return false;
			}
			int start = 0;
			stack<int> s;
			int m = pushV.size();
			for(int i = 0 ; i < m ; i++){
				while(s.empty() || s.top() != popV[i]){
					if(start >= m){
						return false;
					}
					s.push(pushV[start++]);
				}
				if(s.top() != popV[i]){
					return false;
				}
				s.pop();
			}
			return true;  
	    }
};

int main()
{
	int m,n;
	while(cin>>m>>n){
		vector<int> push(m),pop(n);
		for(int i = 0 ; i < m ; i++){
			cin>>push[i];
		}
		for(int i = 0 ; i < n ; i++){
			cin>>pop[i];
		}
		Solution s;
		cout<<s.IsPopOrder(push,pop);
	}
	
	return 0;
 } 
