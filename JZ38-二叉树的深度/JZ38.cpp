#include <iostream>
#include <cstdlib>
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
	    int TreeDepth(TreeNode* pRoot){
	    	if(pRoot == NULL){
	    		return 0;
			}
			int left_depth = this->TreeDepth(pRoot->left);
			int right_depth = this->TreeDepth(pRoot->right);
			return max(left_depth,right_depth)+1;
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
		cout<<s.TreeDepth(root);
	}
	
	return 0;
}
