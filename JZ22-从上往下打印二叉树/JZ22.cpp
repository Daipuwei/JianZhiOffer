#include <iostream>
#include <cstdlib>
#include <queue>
#include <vector> 
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
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

class Solution {
	public:
	    vector<int> PrintFromTopToBottom(TreeNode* root) {
			vector<int> result;
			if(root == NULL){
				return result;
			}
			queue<TreeNode*> q;
			q.push(root);
			while(!q.empty()){
				TreeNode* node = q.front();
				q.pop();
				result.push_back(node->val);
				if(node->left){
					q.push(node->left);
				}
				if(node->right){
					q.push(node->right);
				}
			}
			return result;
	    }
};

int main()
{
	while(true){
		TreeNode* root = Create_BinaryTree();
		Solution s;
		vector<int> result = s.PrintFromTopToBottom(root);
		for(int i = 0 ; i < result.size() ; i++){
			cout<<result[i]<<" "; 
		}
	}
	
	return 0;
 } 
