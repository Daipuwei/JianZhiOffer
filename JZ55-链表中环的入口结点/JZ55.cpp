#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* Find(ListNode* pHead, int value)
{
	if(pHead== NULL){
		return NULL;
	}
	ListNode* node = pHead;
	ListNode* ans = NULL;
	while(node != NULL){
		if(node->val == value){
			ans = node;
			break;
		}
		node = node->next;
	}
	return ans;
} 

class Solution {
	public:
	    ListNode* EntryNodeOfLoop(ListNode* pHead){ 
			if(pHead == NULL){  	//链表为空 
	    		return NULL;
			}
			
			//首指针走一步，尾指针走两步，判断链表是否存在环 
			ListNode* front = pHead;
			ListNode* rear = pHead->next;
			while(front != rear && front != NULL && rear != NULL){
				front = front->next;
				rear = rear->next;
				if(rear != NULL){
					rear = rear->next;
				}
			}
			
			int cnt = 1;			//记录环长度 
			ListNode* tmp = rear->next;
			if(front == rear && front != NULL){
				while(tmp != front){
					cnt++;
					tmp = tmp->next;
				}
			}else{
				return NULL;
			}
			
			ListNode* tmp1 = pHead;
			ListNode* tmp2 = pHead;
			for(int i = 0 ; i < cnt ; i++){
				tmp1 = tmp1->next;
			}
			while(tmp1 != tmp2){
				tmp1 = tmp1->next;
				tmp2 = tmp2->next; 
			}
			return tmp1;
	    }
};

int main()
{
	int n,flag,val1,val2;
	Solution s;
	while(cin>>n>>flag){
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
		if(flag){
			cin>>val1>>val2;
			ListNode* node1 = Find(head,val1);
			ListNode* node2 = Find(head,val2);
			node2->next = node1;
		}
		ListNode* node = s.EntryNodeOfLoop(head);
		if(node != NULL){
			cout<<node->val<<endl;
		}else{
			cout<<"NULL"<<endl;
		}
	} 
	
	return 0;
} 
