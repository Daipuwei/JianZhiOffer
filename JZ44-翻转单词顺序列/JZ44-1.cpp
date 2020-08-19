#include <iostream>
#include <string>
using namespace std;

class Solution {
	public:
	    string ReverseSentence(string str) {
			int len = str.length();
			if(len == 0){
				return str;
			}
			str.push_back(' ');			//为了方便处理 
			len = str.length(); 
			char* ch = (char*) str.c_str();
			int start = 0 , end = 0;
			string ans = "";
			for(end = start ; end < len ; end++){
				if(ch[end] == ' '){
					break;
				}
			}
			ans += str.substr(start,end-start);
			start = end+1;
			end = start;
			for(; end < len ; end++){
				if(ch[end] == ' '){
					ans = " "+ans;
					ans = str.substr(start,end-start)+ans; 
					start = end+1;
					end = start;	
				}
			}
			return ans;
		}
};

int main()
{	Solution s;
	while(true){
		string str;
		getline(cin, str);
		cout<<s.ReverseSentence(str);
	}
	
	return 0;
}
