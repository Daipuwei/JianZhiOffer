#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution {
	public:
	    vector<string> Permutation(string str) {
			vector<string> ans;
			if(str == ""){
				return ans;
			}    
			set<string> result;
			dfs(result,str,str.length(),0);
			for(set<string>::iterator it = result.begin() ; it != result.end() ; it++){
				ans.push_back(*it);
			}
			return ans; 
	    }
	    
	    void dfs(set<string> &ans,string str,int len,int cnt){
	    	if(cnt == len){
	    		ans.insert(str);
			}else{
				for(int i = cnt ; i < len ; i++){
					char tmp = str[cnt]; 
					str[cnt] = str[i];
					str[i] = tmp;
					dfs(ans,str,len,cnt+1);
					tmp = str[cnt];
					str[cnt] =str[i];
					str[i] = tmp;
				}
			}
		}
}; 

int main()
{
	string str;
	while(cin>>str){
		Solution s;
		vector<string> ans = s.Permutation(str);
		for(int i = 0 ; i < ans.size() ; i++){
			cout<<ans[i]<<endl; 
		}
	} 
	
	return 0;
}
