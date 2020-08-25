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
	    ListNode* deleteDuplication(ListNode* pHead){
	    	if(pHead == NULL){
	    		return NULL;
			}
			if(pHead->next == NULL){
				return pHead;
			}
			ListNode* head = new ListNode(0);
			head->next = pHead;
			ListNode* tmp = head;
			while(1){
				ListNode* front = tmp->next;
				if(front == NULL){
					break;
				}
				ListNode* rear = front->next;
				if(rear && rear->val == front->val){
					while(rear && rear->val == front->val){
						rear = rear->next;
					}
					tmp->next = rear;
				}else{
					tmp = tmp->next; 	
				}
			}
			return head->next;
	    }
};

int main()
{
	int n,val;
	Solution s;
	while(cin>>n){
		ListNode* head = new ListNode(0);
		ListNode* tmp = head;
		for(int i = 0 ; i < n ; i++){
			cin>>val;
			ListNode* node = new ListNode(val);
			head->next = node;
			head = head->next;
		}
		head = tmp->next;
		ListNode* head1 = s.deleteDuplication(head);
		while(head1){
			cout<<head1->val<<" ";
			head1 = head1->next;
		}
	}
	
	return 0;
}
