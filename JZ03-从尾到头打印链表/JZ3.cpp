#include <iostream>
using namespace std;
#include <vector>

struct ListNode {
        int val;
        struct ListNode *next;
        ListNode(int x) :
              val(x), next(NULL) {
        }
};

class Solution {
	public:
	    vector<int> printListFromTailToHead(ListNode* head) {
	    	vector<int> result;
	    	if(head == NULL){
				return result;
			}
			ListNode* front = head;
			ListNode* rear = front->next;
			front->next = NULL;
			while(rear){
				ListNode* tmp = rear->next;
				rear->next = front;
				front = rear;
				rear = tmp;
			}
			while(front != NULL){
				result.push_back(front->val);
				front = front->next;
			}
			return result;
	    }
};

int main(){
	ListNode* head = new ListNode(0);
	cout<<head->val<<endl;
	ListNode* tmp = head;
	for(int i = 1 ; i <= 3 ; i++){
		ListNode* p = new ListNode(i);
		tmp->next = p;
		tmp = tmp->next;
	}
	
	struct ListNode* tmp1 = head;
	while(tmp1){
		cout<<tmp1->val<"  ";
		tmp1 = tmp1->next;
	}
	cout<<endl;
	
	Solution s;
	vector<int> result = s.printListFromTailToHead(head);
	for(int i = 0 ; i < result.size() ; i++){
		cout<<result[i]<<" ";
	}
	
	return 0;
}
