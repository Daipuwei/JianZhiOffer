#include <iostream>
using namespace std;

class Solution {
	public:
	    bool match(char* str, char* pattern){
	    	if(str == NULL || pattern == NULL){		// 字符串或模式为空，直接返回false 
	    		return false;
			}
	    	return this->matchCore(str,pattern);
		}
	    
	    bool matchCore(char* str, char* pattern){
	    	if(pattern[0] == 0 && str[0] == 0){		//字符串和模式首元素为空直接返回true 
	    		return true;
			}
			
			if(pattern[0] != 0 && pattern[1] == '*'){	//模式首元素被空，第2个元素为'*', 
				if(this->matchCore(str,pattern+2)){  //判断字符串与模式串右移2为的子串是否匹配，匹配这返回true 
					return true;
				}
			}
			
			if(str[0] == pattern[0] ||(str[0] != 0 && pattern[0] == '.')){		// 字符串和模式首元素相等或者模式首元素为'.' 
				if(this->matchCore(str+1,pattern+1)){		// 字符串和模式指针加1，判断是否匹配，若是则返回true 
					return true;
				}
				if(pattern[1] == '*' && this->matchCore(str+1,pattern)){		//模式第二个元素为'*',并且字符串+1的子串与模式匹配则返回true 
					return true;
				}
			}
			
			return false;
		}
};


int main()
{
	string str,pattern;
	Solution s;
	while(cin>>str>>pattern){
		char* str1 = (char*)str.c_str();
		char* pattern1 = (char*)pattern.c_str();
		cout<<s.match(str1,pattern1);
	}	
	
	return 0;
} 
