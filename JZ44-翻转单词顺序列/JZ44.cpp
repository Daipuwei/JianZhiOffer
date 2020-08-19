#include <iostream>
#include <string>
using namespace std;

class Solution {
	public:
	    string ReverseSentence(string str) {
	        if(str.empty()){			//×Ö·û´®Îª¿Õ 
	        	return str;
			}
			
			int size = str.length();
			int i = 0;
			while(i < size && str[i] == ' '){
				i++;
			} 
			if(i == size){			//×Ö·û´®È«Îª¿Õ¸ñ 
				return str;
			}
			
			string tmp = "";
			string result = "";
			bool flag = false;
			for(i = size-1 ; i >= 0 ; i--){
				if(str[i] != ' '){
					tmp = str[i]+tmp;
					flag = true; 
				}else if(str[i] == ' ' && flag){
					result = result + tmp + " ";
					tmp = "";
					flag = false;
				}
			}
			if(tmp != ""){
				result = result + tmp;
			}
			return result; 
	    }
};

int main()
{
	Solution s;
	while(true){
		string str;
		getline(cin, str);
		cout<<s.ReverseSentence(str);
	}
	
	return 0;
 } 
