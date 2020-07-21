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
    if(ch == '#'){                                                  //��#���ǽ�����־ 
        T = NULL;
    }else{
        T->val = int(ch);                                           //�Ե�ǰ����ʼ�� 
        T->left = Create_BinaryTree();                            //�ݹ鹹�������� 
        T->right = Create_BinaryTree();                            //�ݹ鹹�������� 
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
