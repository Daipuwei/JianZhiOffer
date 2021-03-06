#include <iostream>
using namespace std;
#include <vector> 

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
	    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
			int size = pre.size();
			int *Pre,*Vin;
			Pre = new int[size];
			Vin = new int[size]; 
			for(int i = 0 ; i < size ; i++){
				Pre[i] = pre[i];
				Vin[i] = vin[i];
			}
			TreeNode* root = this->Build(Pre,Vin,size);
			return root;
	    }
	    
	    TreeNode* Build(int* Pre,int* Vin,int size){
	    	if(!Pre || !Vin || size < 0){
				return NULL;
			}
	    	int root_index = 0;
	    	for(root_index = 0 ; root_index < size ; root_index++){
				if(Pre[0] == Vin[root_index]){
					break;
				}
			}
			
			if(root_index == size){
				return NULL;
			}
			
			TreeNode* root;
			root = new TreeNode(Pre[0]);
			if(root_index > 0){
				root->left = this->Build(Pre+1,Vin,root_index);
			}
			if(size - root_index - 1> 0){
				root->right = this->Build(Pre+root_index+1,Vin+root_index+1,size-root_index-1);
			}
			return root;
		}
	    
};                  

int main(){
	
	
	return 0;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
