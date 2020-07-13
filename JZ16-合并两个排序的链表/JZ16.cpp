#include <iostream>
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
	    ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
	        ListNode* head = new ListNode(0);
	        ListNode* tmp = head;
	        ListNode* node;
			while(pHead1 && pHead2){
				if(pHead1->val <= pHead2->val){
					node = new ListNode(pHead1->val);
					pHead1 = pHead1->next;
				}else{
					node = new ListNode(pHead2->val); 
					pHead2 = pHead2->next;
				}
				tmp->next = node; 
				tmp = tmp->next;
			}
			if(pHead1){
				tmp->next = pHead1;
			}
			if(pHead2){
				tmp->next = pHead2;
			}
			head = head->next;
			return head;
	    }
};
int main(){
	int n,m;
	while(cin>>n>>m){
		ListNode* head1 = new ListNode(0);
		ListNode* head2 = new ListNode(0);
		ListNode* tmp = head1;
		int v;
		for(int i = 0 ; i < n ; i++){
			cin>>v;
			ListNode* node = new ListNode(v);
			head1->next = node;
			head1 = head1->next;
		}
		head1 = tmp->next;
		
		tmp = head2;
		for(int i = 0 ; i < m ; i++){
			cin>>v;
			ListNode* node = new ListNode(v);
			head2->next = node;
			head2 = head2->next;
		}
		head2 = tmp->next;
		
		tmp = head1;
		while(tmp){
			cout<<tmp->val<<" ";
			tmp = tmp->next;
		}
		cout<<endl;
		
		tmp = head2;
		while(tmp){
			cout<<tmp->val<<" ";
			tmp = tmp->next;
		}
		cout<<endl;
		
		Solution s;
		tmp = s.Merge(head1,head2);
		while(tmp){
			cout<<tmp->val<<" ";
			tmp = tmp->next; 
		}
	} 
	
	return 0;
}

