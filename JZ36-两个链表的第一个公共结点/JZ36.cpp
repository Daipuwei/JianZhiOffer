#include <iostream>
#include <stack>
#include <cmath>
using namespace std; 

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
	public:
	    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
	    	ListNode* ans = NULL;
	        if(pHead1 == NULL || pHead2 == NULL){
	        	return ans;
			}
			stack<ListNode*> stack1,stack2;
	        ListNode* tmp1 = pHead1;
	        ListNode* tmp2 = pHead2;
	        while(tmp1 && tmp2){
	        	stack1.push(tmp1);
	        	stack2.push(tmp2);
	        	tmp1 = tmp1->next;
	        	tmp2 = tmp2->next;
			}
			while(tmp1){
				stack1.push(tmp1);
	        	tmp1 = tmp1->next;
			}
			while(tmp2){
				stack2.push(tmp2);
	        	tmp2 = tmp2->next;
			}
			
			while(!stack1.empty() && !stack2.empty()){
				ListNode* node1 = stack1.top();
				ListNode* node2 = stack2.top();
				stack1.pop();
				stack2.pop();
				if(node1->val == node2->val){
					ans = node1;
				}else{
					break;
				}
			}
			return ans;
	    }
};



int main()
{
	int m,n,val,val1;
	while(cin>>m>>n){
		ListNode* head1 = new ListNode(0);
		ListNode* head2 = new ListNode(0);
		ListNode* tmp1 = head1;
		ListNode* tmp2 = head2;
		if(m > n){
			for(int i = 0 ; i < m-n; i++){
				cin>>val;
				ListNode* node = new ListNode(val);
				tmp1->next = node;
				tmp1 = tmp1->next;
			}
		}else if(m < n){
			for(int i = 0 ; i < n-m; i++){
				cin>>val;
				ListNode* node = new ListNode(val);
				tmp2->next = node;
				tmp2 = tmp2->next;
			}
		}else{
			;
		}
		int cnt = min(m,n);
		for(int i = 0 ; i < cnt ; i++){
			cin>>val>>val1;
			if(val != val1){
				ListNode* node1 = new ListNode(val);
				ListNode* node2 = new ListNode(val1);
				tmp1->next = node1;
				tmp2->next = node2;
				tmp1 = tmp1->next;
				tmp2 = tmp2->next; 	
			}else{
				ListNode* node = new ListNode(val);
				tmp1->next = node;
				tmp2->next = node;
				tmp1 = tmp1->next;
				tmp2 = tmp2->next; 	
			}
		}
		Solution s;
		ListNode* node = s.FindFirstCommonNode(head1,head2);
		cout<<node->val;
	}
	
	return 0;
}
