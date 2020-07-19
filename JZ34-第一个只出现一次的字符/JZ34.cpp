#include <iostream>
#include <map>
using namespace std;

class Solution {
	public:
	    int FirstNotRepeatingChar(string str) {
			if(str.length() == 0){
				return -1;
			}
			map<char,int> cnt;				// ��¼ÿ���ַ��ĳ��ִ��� 
			for(int i = 0 ; i < str.length() ; i++){
				cnt[str[i]]++;
			}  
			int ans = -1;
			for(int i = 0 ; i < str.length() ; i++){
				if(cnt[str[i]] == 1){
					ans = i;
					break;
				}
			}
			return ans; 
	    }
}; 

int main()
{
	string str;
	while(cin>>str){
		Solution s;
		cout<<s.FirstNotRepeatingChar(str); 
	}
	
	return 0;
}
