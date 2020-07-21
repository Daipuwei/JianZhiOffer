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
	    	int depth = 0;
	    	return this->IsBalanced(pRoot,&depth);
	    }
	    
	    bool IsBalanced(TreeNode* pRoot,int* depth) {
	    	if(pRoot == NULL){
	    		*depth = 0;
	    		return true;
			}
			int left_depth = 0,right_depth = 0;
			if(this->IsBalanced(pRoot->left,&left_depth) && this->IsBalanced(pRoot->right,&right_depth)){
				int diff = abs(left_depth-right_depth);
				if(diff <= 1){
					*depth = 1 + max(left_depth,right_depth);
					return true;
				}
			}
			return false;
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
