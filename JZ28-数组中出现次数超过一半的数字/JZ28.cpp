#include <iostream>
#include <vector>
#include <map>
using namespace std;
 
class Solution {
	public:
	    int MoreThanHalfNum_Solution(vector<int> numbers) {
	    	if(numbers.size() == 0){
	    		return 0;
			}
	    	if(numbers.size() == 1){
	    		return numbers[0];
			}
			map<int,int> Map;
			int size = numbers.size();
			for(int i = 0 ; i < size ; i++){
				Map[numbers[i]]++;
			}
			map<int,int>::iterator it;
			int result = 0;
			for(it = Map.begin() ; it != Map.end() ; it++){
				if(it->second * 2 > size){
					result = it->first;
					break;
				}
			}
			return result;
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
		cout<<s.MoreThanHalfNum_Solution(array);
	}
	
	return 0;
}
