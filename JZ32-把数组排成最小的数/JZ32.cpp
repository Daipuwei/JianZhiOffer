#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;


int cmp(int a , int b)
{
	ostringstream s1,s2;
		s1<<a;
		s2<<b;
		string str1 = s1.str() + s2.str();
		string str2 = s2.str() + s1.str();
		return str1 < str2; 
}


class Solution {
	public:
	    string PrintMinNumber(vector<int> numbers) {
	    	string ans = "";
	    	if(numbers.size() == 0){
	    		return ans;
			}
			sort(numbers.begin(),numbers.end(),cmp);
	    	for(int i = 0 ; i < numbers.size() ; i++){
	    		ostringstream  s;
	    		s<<numbers[i];
	    		ans += s.str();
			}
			return ans;
	    }
};

int main()
{
	int n;
	while(cin>>n){
		vector<int> array(n);
		for(int i = 0 ; i < n ; i++){
			cin>>array[i];
		}
		Solution s;
		cout<<s.PrintMinNumber(array);
	}
	
	return 0;
 } 
