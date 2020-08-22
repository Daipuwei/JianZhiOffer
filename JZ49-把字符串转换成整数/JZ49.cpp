#include <iostream>
using namespace std;

class Solution {
	public:
	    int StrToInt(string str){
			if(str== "" || str.length() == 0){
				return 0;
			}
			
			// 分离正负号 
			bool isgreater0;
			int size = str.length();
			if(str[0] == '-'){
				isgreater0 = false;
				str = str.substr(1,size);
			}else if(str[0] == '+'){
				isgreater0 = true;
				str = str.substr(1,size);
			}else{
				isgreater0 = true;
			}
			
			//判断字符串是否全为数字
			if(!this->isNumber(str)){
				return 0;
			}
			
			int result = 0;
			for(int i = 0 ; i < str.length() ; i++){
				result = result * 10 + (str[i]- '0');
			}
			if(!isgreater0){
				result = -result;
			}
			return result;
	    }
	    
	    bool isNumber(string str){
			bool flag = true;
			for(int i = 0 ; i < str.length() ; i++){
				if(!(str[i] >= '0' && str[i] <= '9')){
					flag = false;
					break;
				}	
			}
			return flag;
		}
};

int main()
{
	string str;
	Solution s;
	while(cin>>str){
		cout<<s.StrToInt(str)<<endl;
		
	}
	
	
	return 0;
 } 
