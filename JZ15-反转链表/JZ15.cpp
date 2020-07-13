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
	    ListNode* ReverseList(ListNode* pHead) {
	    	if(pHead == NULL){
	    		return NULL;
			}
			ListNode* front = pHead;
			ListNode* rear = front->next;
			front->next = NULL; 
			ListNode* tmp;
			while(rear){
				tmp = rear->next;
				rear->next = front;
				front = rear;
				rear = tmp;
			}
			return front;
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
		tmp = head;
		while(tmp){
			cout<<tmp->val<<" ";
			tmp = tmp->next;
		}
		cout<<endl;
		Solution s;
		tmp = s.ReverseList(head);
		while(tmp){
			cout<<tmp->val<<" ";
			tmp = tmp->next; 
		}
	} 
	
	return 0;
}
