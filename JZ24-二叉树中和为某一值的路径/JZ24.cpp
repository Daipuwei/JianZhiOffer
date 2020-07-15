#include <iostream>
#include <vector>
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
	    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
	    	vector<vector<int> > ans;
	    	vector<int> path;
	    	if(root == NULL || root->val > expectNumber){
	    		return ans;
			}
			this->find(root,expectNumber,path,ans); 
			return ans;
	    }
	    
	    void find(TreeNode* root,int number,vector<int>& path,vector<vector<int> >& ans){
	    	if(root == NULL || root->val > number){
	    		path.clear();
			}else if(root->val == number){
				if(root->left == NULL && root->right == NULL){
					path.push_back(root->val);
					ans.push_back(path);
				}else{
					path.clear();
				}
			}else{
				path.push_back(root->val);
				number -= root->val;
				vector<int> tmp;
				for(int i = 0 ; i < path.size() ; i++){
					tmp.push_back(path[i]);
				}
				this->find(root->left,number,path,ans);
				this->find(root->right,number,tmp,ans);
			}
			
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

int main()
{
	int number;
	while(cin>>number){
		TreeNode* root = Create_BinaryTree();
		Solution s;
		vector<vector<int> > ans = s.FindPath(root,number);
		cout<<ans.size()<<endl;
		cout<<ans[0].size()<<endl;
		for(int i = 0 ; i < ans.size() ; i++){
			for(int j = 0 ; j < ans[i].size() ; j++){
				cout<<ans[i][j]<<" "; 
			}
			cout<<endl;
		}
	}
	
	return 0;
}
