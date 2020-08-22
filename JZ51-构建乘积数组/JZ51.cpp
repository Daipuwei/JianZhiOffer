#include <iostream>
#include <vector>
using namespace std; 

class Solution {
	public:
	    vector<int> multiply(const vector<int>& A) {
	    	vector<int> B(A.size(),1);
	    	for(int i = 1 ; i < A.size() ; i++){
	    		B[i] = B[i-1]*A[i-1];
			}
			int tmp = 1;
			for(int i = A.size()-2 ; i >= 0 ; i--){
				tmp *= A[i+1];
				B[i] *= tmp;
			}
			return B;
	    }
};

int main()
{
	int n;
	Solution s;
	while(cin>>n){
		vector<int> A(n);
		for(int i = 0 ; i < n ; i++){
			cin>>A[i];
		}
		vector<int> B = s.multiply(A);
		for(int i = 0 ; i < B.size() ; i++){
			cout<<B[i]<<" ";
		}
	}
	
	return 0;
}
