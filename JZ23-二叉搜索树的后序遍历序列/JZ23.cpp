#include <iostream>
#include <vector>
using namespace std;

 
class Solution {
	public:
	    bool VerifySquenceOfBST(vector<int> sequence) {
	    	int size = sequence.size();
	    	return this->veriftBST(sequence,0,size-1);
	    }
	    
	    bool veriftBST(vector<int> sequence , int start, int end){
	    	if(sequence.empty() || start > end){
	    		return false;
			}
			
			int root = sequence[end];
			//�ҵ����������ķֽ��
			int index = start; 
			for(index = start ; index < end ; index++){
				if(sequence[index] > root){
					break;
				}
			}
			//indexΪ�������ĵ�һ��Ԫ���±� 
			for(int i = index ; i < end ; i++){
				if(sequence[i] < root){
					return false;
				}
			}
			bool left = true;
			if(index > start){		//�������� 
				left = this->veriftBST(sequence,start,index-1);
			}
			bool right = true;
			if(end-1 > index){
				right = this->veriftBST(sequence,index,end-1);
			}
			return left && right;
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
		cout<<s.VerifySquenceOfBST(array);
	}
	
	return 0;
}
