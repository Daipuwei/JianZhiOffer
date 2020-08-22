#include <iostream>
#include <map>
#include <set>
#include <cstring>
using namespace std;

class Solution {
	public:
	    // Parameters:
	    //        numbers:     an array of integers
	    //        length:      the length of array numbers
	    //        duplication: (Output) the duplicated number in the array number
	    // Return value:       true if the input is valid, and there are some duplications in the array number
	    //                     otherwise false
	    bool duplicate(int numbers[], int length, int* duplication) {
	        // 判断数组是否为空 
			if(numbers == NULL || length <= 0){
	        	return false;
			}
			 
			map<int,int> number_hash;
			set<int> number_set;
			for(int i = 0 ; i < length ; i++){
				number_hash[numbers[i]]++;
				number_set.insert(numbers[i]);
			}
			
			int cnt = 0;
			set<int>::iterator it;
			for(it = number_set.begin() ; it != number_set.end() ; it++){
				if(number_hash[*it] > 1){
					duplication[cnt++] = *it;
					return true;
				}
			}
			return false;
	    }
};

int main()
{
	int n;
	Solution s;
	while(cin>>n){
		int* array = new int[n];
		int* duplication = new int[n];
		memset(array,0,sizeof(int)*n);
		memset(duplication,0,sizeof(int)*n);
		for(int i = 0; i < n ; i++){
			cin>>array[i];
		}
		bool flag = s.duplicate(array,n,duplication);
		if(flag){
			for(int i = 0 ; i < n ; i++){
				cout<<duplication[i]<<" ";
			}
			cout<<endl;
		}
	}
	
	
	return 0;
}

