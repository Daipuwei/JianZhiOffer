#include <iostream>
#include <string>
using namespace std;

class Solution {
	public:
	    string LeftRotateString(string str, int n) {
			int len = str.length();
			char* ch = (char*)str.c_str();
			this->reverse(ch,0,len-1,len);
			this->reverse(ch,0,len-n-1,len);
			this->reverse(ch,len-n,len-1,len);
			string result = "";
			for(int i = 0 ; i < len ; i++){
				result.push_back(ch[i]);
			}
			return result;
	    }
	    
	    void reverse(char* ch,int start,int end,int len){
	    	if(start >= end || end >= len){
	    		return;
			}
			int mid = (start + end) / 2;
			for(int i = 0 ; i <= mid-start ; i++){
				char tmp = ch[end-i];
				ch[end-i] = ch[i+start];
				ch[i+start] = tmp;
			}
		}
};

int main()
{
	string str;
	int size;
	Solution s;
	while(cin>>size>>str){
		cout<<s.LeftRotateString(str,size)<<endl;
	}
	
	return 0;
 } 
