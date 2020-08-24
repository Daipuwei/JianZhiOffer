#include <iostream>
using namespace std;

class Solution {
	public:
	    bool match(char* str, char* pattern){
	    	if(str == NULL || pattern == NULL){		// �ַ�����ģʽΪ�գ�ֱ�ӷ���false 
	    		return false;
			}
	    	return this->matchCore(str,pattern);
		}
	    
	    bool matchCore(char* str, char* pattern){
	    	if(pattern[0] == 0 && str[0] == 0){		//�ַ�����ģʽ��Ԫ��Ϊ��ֱ�ӷ���true 
	    		return true;
			}
			
			if(pattern[0] != 0 && pattern[1] == '*'){	//ģʽ��Ԫ�ر��գ���2��Ԫ��Ϊ'*', 
				if(this->matchCore(str,pattern+2)){  //�ж��ַ�����ģʽ������2Ϊ���Ӵ��Ƿ�ƥ�䣬ƥ���ⷵ��true 
					return true;
				}
			}
			
			if(str[0] == pattern[0] ||(str[0] != 0 && pattern[0] == '.')){		// �ַ�����ģʽ��Ԫ����Ȼ���ģʽ��Ԫ��Ϊ'.' 
				if(this->matchCore(str+1,pattern+1)){		// �ַ�����ģʽָ���1���ж��Ƿ�ƥ�䣬�����򷵻�true 
					return true;
				}
				if(pattern[1] == '*' && this->matchCore(str+1,pattern)){		//ģʽ�ڶ���Ԫ��Ϊ'*',�����ַ���+1���Ӵ���ģʽƥ���򷵻�true 
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
