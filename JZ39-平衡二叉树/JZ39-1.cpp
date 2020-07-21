#include <iostream>
#include <cmath> 
using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
	public:
	    bool IsBalanced_Solution(TreeNode* pRoot) {
			if(pRoot == NULL){
				return true;
			}
			return this->check_Height(pRoot);
	    }
	    
	    bool check_Height(TreeNode* pRoot){
	    	if(pRoot == NULL){
				return true;
			}
			int left = this->TreeDepth(pRoot->left);
			int right = this->TreeDepth(pRoot->right);
			bool flag;
			if(abs(left-right) <= 1){
				return this->IsBalanced_Solution(pRoot->left) && this->IsBalanced_Solution(pRoot->right); 
			}else{
				return false;
			}
		}
	    
	    int TreeDepth(TreeNode* pRoot){
	    	if(pRoot == NULL){
	    		return 0;
			}
			int left = this->TreeDepth(pRoot->left);
			int right = this->TreeDepth(pRoot->right);
	    	return (left>right)?left+1:right+1;
		}
};

TreeNode* Create_BinaryTree()
{
    TreeNode* T = new TreeNode(0);
    char ch;
    cin>>ch;
    if(ch == '#'){                                                  //“#”是结束标志 
        T = NULL;
    }else{
        T->val = int(ch);                                           //对当前结点初始化 
        T->left = Create_BinaryTree();                            //递归构造左子树 
        T->right = Create_BinaryTree();                            //递归构造右子树 
    }
    return T;
}


int main()
{
	while(true){
		TreeNode* root = Create_BinaryTree();
		Solution s;
		cout<<s.IsBalanced_Solution(root);
	}
	
	return 0;
}
