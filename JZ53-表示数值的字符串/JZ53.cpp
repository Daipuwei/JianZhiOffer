#include <iostream>
#include <cstring>
using namespace std;

class Solution {
	public:
		bool check_science(char* str){
			int length = strlen(str);
			int j = 0;
			if(str[0] == '+' || str[0] == '-'){
				j = 1;
			}
			bool flag1 = true;
			for(; j < length ; j++){
				if(str[j] == '.' ){
					flag1 = false;
					break;
				}else if((str[j] >= 'a' && str[j] <= 'z') || (str[j] >= 'A' && str[j] <= 'Z')){
					flag1 = false;
					break;
				}else if(str[j] == '+' || str[j] == '-'){
					flag1 = false;
					break;
				}else if(str[j] >= '0' || str[j] <= '9'){
					continue;
				}
			}
			return flag1;
		}
		
	    bool isNumeric(char* string){
	    	if(string == NULL || string[0] == '.'){
	    		return false;
			}
			int cnt = 0;		//小数点个数
			bool flag = true;	
			int i = 0;
			int len = strlen(string);
			if(string[0] == '+' || string[0] == '-'){
				i = 1;
			} 
			for(; i < len ; i++){
				if((string[i] >= 'a' && string [i] <= 'd') || (string[i] >= 'f' && string [i] <= 'z') ||
					(string[i] >= 'A' && string [i] <= 'D') || (string[i] >= 'F' && string [i] <= 'Z')){
						flag = false;
						break;
				}else{
					if(string[i] == '+' || string[i] == '-'){
						flag = false;
						break;
					}else if(string[i] >= '0' && string[i] <= '9'){
						continue;
					}else if(string[i] == '.'){
						if(cnt == 0){
							cnt++;
						}else{
							flag = false;
							break;
						}
					}else if(string[i] == 'e' || string[i] == 'E'){
						if(i == len-1){
							flag = false;
							break;
						}else{
							flag = this->check_science(string+2);
							break;
						}
					}
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
		char* string = (char*) str.c_str();
		cout<<s.isNumeric(string)<<endl;
	}
	
	return 0;
} 
