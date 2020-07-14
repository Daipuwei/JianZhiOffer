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
			if(pRoot == NULL){			//��Ϊ��
				return;
			}
			if(pRoot->left == NULL && pRoot->right == NULL){		//��ֻ�и��ڵ� 
				return;
			}
			// ������������Ե�
			TreeNode* tmp = pRoot->left;
			pRoot->left = pRoot->right;
			pRoot->right = tmp;
			
			// �ݹ�Ե���������������
			this->Mirror(pRoot->left);
			this->Mirror(pRoot->right); 
	    }
}; 

TreeNode* Create_BinaryTree()
{
    TreeNode* T = new TreeNode(0);
    string s;
    cin>>s;
    if(s == "#"){                                                  //��#���ǽ�����־ 
        T = NULL;
    }else{
        T->val = atoi(s.c_str());                                           //�Ե�ǰ����ʼ�� 
        T->left = Create_BinaryTree();                            //�ݹ鹹�������� 
        T->right = Create_BinaryTree();                            //�ݹ鹹�������� 
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
