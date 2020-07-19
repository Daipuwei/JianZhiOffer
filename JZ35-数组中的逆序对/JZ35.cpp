#include <iostream>
#include <vector>
using namespace std; 

class Solution {
	public:
	    int InversePairs(vector<int> data) {
	    	int len = data.size();
			if(len <= 0){
				return 0;
			}
			vector<int> copy;
			for(int i = 0 ; i < len ; i++){
				copy.push_back(data[i]);
			}
			long long cnt = this->InversePairsCore(data,copy,0,len-1);
			return cnt % 1000000007;
	    }
	    
	    long long InversePairsCore(vector<int> &data,vector<int> &copy,int start,int end){
	    	if(start == end){
	    		copy[start] = data[start];
	    		return 0;
			}
			int len = (end - start) / 2;
			long long left = this->InversePairsCore(copy,data,start,start+len);
			long long right = this->InversePairsCore(copy,data,start+len+1,end);
			
			int i = start + len;
			int j = end;
			int indexcopy = end;
			long long cnt = 0;
			while(i >= start && j >= start+len+1){
				if(data[i] > data[j]){
					copy[indexcopy--] = data[i--];
					cnt = cnt + j - start -len;
				}else{
					copy[indexcopy--] = data[j--];
				}
			}
			for(; i >= start ; i--){
				copy[indexcopy--] = data[i];
			}
			for(; j >= start+len+1 ; j--){
				copy[indexcopy--] = data[j];
			}
			return left+right+cnt;
		}
};

int main()
{
	int n;
	while(cin>>n){
		vector<int> ans(n);
		for(int i = 0 ; i < n ; i++){
			cin>>ans[i];
		}
		Solution s;
		cout<<s.InversePairs(ans);
	}
	
	return 0;
}
