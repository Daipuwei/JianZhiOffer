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
	    TreeNode* Convert(TreeNode* pRootOfTree){
	        if(pRootOfTree == NULL){
	        	return NULL;
			}
			TreeNode* last = NULL;
			Convert2List(pRootOfTree,last);
			while(pRootOfTree->left){
				pRootOfTree = pRootOfTree->left;
			}
			return pRootOfTree;
	    }
	    
	    void Convert2List(TreeNode* root,TreeNode* &last){
	    	if(root == NULL){
	    		return;
			}
	    	if(root->left != NULL){
	    		Convert2List(root->left,last);
			}
			root->left = last;
			if(last != NULL){
				last->right = root;
			}
			last = root;
			if(root->right != NULL){
				Convert2List(root->right,last);		
			}
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
        T->val = atoi(s.c_str());                                   //�Ե�ǰ����ʼ�� 
        T->left = Create_BinaryTree();                             //�ݹ鹹�������� 
        T->right = Create_BinaryTree();                            //�ݹ鹹�������� 
    }
    return T;
}

int main()
{
	while(true){
		TreeNode* root = Create_BinaryTree();
		Solution s;
		TreeNode* head = s.Convert(root);
		while(head){
			cout<<head->val<<" ";
			head = head->right; 
		}
	}
	
	return 0;
}
