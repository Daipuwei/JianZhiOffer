#include <iostream>
#include <cstdlib>
#include <cmath>
#include <queue>
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
			queue<TreeNode*> q;
			TreeNode* front = pRoot;
			TreeNode* last = pRoot;
			int depth = 0;
			q.push(pRoot);
			while(!q.empty()){
				depth++;
				int size = q.size();
				while(size--){
					TreeNode* node = q.front();
					q.pop();
					if(node->left){
						q.push(node->left);
					}
					if(node->right){
						q.push(node->right);
					}	
				}
			}
			return depth;
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
