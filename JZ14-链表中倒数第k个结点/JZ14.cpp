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
	    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	    	if(pListHead == NULL || k <= 0){
	    		return NULL;
			}
	    	ListNode* p1 = pListHead;
	    	ListNode* p2 = pListHead;
	    	int cnt = k-1;
			for(int i = 0 ; i <= k-1 ; i++){
				p1 = p1->next;
			}
			while(p1){
				p1 = p1->next;
				p2 = p2->next;
			} 
			return p2;
	    }
}; 

int main(){
	int n;
	while(cin>>n){
		ListNode* head = new ListNode(0);
		ListNode* tmp = head;
		int v;
		for(int i = 0 ; i < n ; i++){
			cin>>v;
			ListNode* node = new ListNode(v);
			head->next = node;
			head = head->next;
		}
		head = tmp->next;
		Solution s;
		cin>>v;
		ListNode* node = s.FindKthToTail(head,v);
		cout<<node->val;
	} 
	
	return 0;
}
