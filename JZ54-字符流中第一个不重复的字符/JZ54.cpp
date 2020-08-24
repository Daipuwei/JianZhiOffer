#include <iostream>
#include <queue>
#include <map>
using namespace std;

class Solution{
	
	private:
		map<char,int> hash;
		queue<char> letter;
		
	public:
	  //Insert one char from stringstream
	    void Insert(char ch){
	    	this->hash[ch]++;
	    	if(this->hash[ch] == 1){
	    		this->letter.push(ch);
			}
		}
	  //return the first appearence once char in current stringstream
	    char FirstAppearingOnce(){
	    	while(!this->letter.empty() && this->hash[this->letter.front()] >= 2){
	    		this->letter.pop();
			}
			if(this->letter.empty()){
				return '#';
			}else{
				return this->letter.front();
			}
	    }

};

int main()
{
	string str;
	Solution s;
	while(cin>>str){
		for(int i = 0 ; i < str.length() ; i++){
			s.Insert(str[i]);
		}
		cout<<s.FirstAppearingOnce()<<endl;
	}
	
	return 0;
}
