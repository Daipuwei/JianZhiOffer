#include <iostream>
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
	    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
	    	if(!pRoot1){
	    		return false;
			}
			if (!pRoot2){
				return false;
			}
	    	return this->dfs(pRoot1,pRoot2) || this->dfs(pRoot1->left,pRoot2) || this->dfs(pRoot1->right,pRoot2);
		}
	    
	    bool dfs(TreeNode* pRoot1, TreeNode* pRoot2){
	    	if(pRoot2 == NULL){
	    		return true;
			}
			if (pRoot1 == NULL){
				return false;
			}
			if(pRoot1->val != pRoot2->val){
				return false;
			}
			return this->dfs(pRoot1->left,pRoot2->left) && this->dfs(pRoot1->right,pRoot2->right);
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


int main(){
	while(true){
		TreeNode* root1 = Create_BinaryTree();
		TreeNode* root2 = Create_BinaryTree();
		Solution s;
		cout<<s.HasSubtree(root1,root2);
	}
	
	return 0;
}
