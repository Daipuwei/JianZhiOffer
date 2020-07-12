#include <iostream>
using namespace std;
#include <string>
 
class Solution {
	public:
		void replaceSpace(char *str,int length) {
			string s = str;
			string _s("%20");
			int cnt = 0; 
			for(int i = 0 ; i < s.length() ; i++){
				if(s[i] == ' '){
					cnt++;
				}
			}
			
			for(int i = 0 ; i < cnt ; i++){
				int index = s.find(' ');
				s.erase(index,1);
				s.insert(index,_s);
			}
			
			for(int i = 0 ; i < s.length() ; i++){
				str[i] = s[i];
			}
			str[s.length()] = '\0';
		}
};

int main(){
	//char c[] = "We Are Happy";
	char c[] = " helloworld";
	int len = 0;
	for(int i = 0 ; c[i] != '\0' ; i++){
		cout<<c[i];
		len++;
	}
	cout<<endl;
	cout<<len<<endl;
	
	Solution s;
	s.replaceSpace(c,len);
	for(int i = 0 ; c[i] != '\0' ; i++){
		cout<<c[i];
	}
	
	return 0;
} 
