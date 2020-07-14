#include <iostream>
#include <cstdlib>
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
	    void Mirror(TreeNode *pRoot) {
			if(pRoot == NULL){			//树为空
				return;
			}
			if(pRoot->left == NULL && pRoot->right == NULL){		//树只有根节点 
				return;
			}
			// 完成左右子树对调
			TreeNode* tmp = pRoot->left;
			pRoot->left = pRoot->right;
			pRoot->right = tmp;
			
			// 递归对调左右子树的子树
			this->Mirror(pRoot->left);
			this->Mirror(pRoot->right); 
	    }
}; 

TreeNode* Create_BinaryTree()
{
    TreeNode* T = new TreeNode(0);
    string s;
    cin>>s;
    if(s == "#"){                                                  //“#”是结束标志 
        T = NULL;
    }else{
        T->val = atoi(s.c_str());                                           //对当前结点初始化 
        T->left = Create_BinaryTree();                            //递归构造左子树 
        T->right = Create_BinaryTree();                            //递归构造右子树 
    }
    return T;
}

void dfs(TreeNode* root)
{
	if(root == NULL){
		return;
	}
	dfs(root->left);
	cout<<root->val<<" ";
	dfs(root->right);
 } 


int main(){
	while(true){
		TreeNode* root = Create_BinaryTree();
		dfs(root);
		Solution s;
		s.Mirror(root);
		cout<<endl; 
		dfs(root);
	}
	
	return 0;
}
