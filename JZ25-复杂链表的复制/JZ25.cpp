#include <iostream>
using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
	public:
	    RandomListNode* Clone(RandomListNode* pHead){ 
			if(pHead == NULL){
				return NULL;
			}
			this->CloneNodes(pHead);			// 实现链表复制,复制后的结点放在原节点之后
			this->connect_random_node(pHead);	// 对复制后的结点的随机指针进行赋值
			RandomListNode* tmp = pHead;
			while(tmp){
				cout<<tmp->label<<" ";
				tmp = tmp->next;
			}
			tmp = pHead;
			while(tmp){
				if(tmp->random == NULL){
					cout<<"#"<<" ";
				}else{
					cout<<tmp->random->label<<" ";
				}
				tmp = tmp->next;
			}
			cout<<endl;
			RandomListNode* clone_list = get_clone_list(pHead);
			return clone_list;
	    }
	    
	    void CloneNodes(RandomListNode* pHead){
	    	RandomListNode* node = pHead;
			while(node != NULL){
				RandomListNode* node_clone = new RandomListNode(node->label);
				node_clone->next = node->next;
				node->next = node_clone;
				node = node_clone->next;
			}
		}
		
		void connect_random_node(RandomListNode* pHead){
			RandomListNode* node = pHead;
			RandomListNode* node_clone = NULL; 
			while(node != NULL){
				node_clone = node->next;
				if(node->random){
					cout<<node->random->label<<endl;
					cout<<node->random->next->label<<endl; 
					node_clone->random = node->random->next;	
				}
				node = node_clone->next;
			}
		}
		
		RandomListNode* get_clone_list(RandomListNode* pHead){
			RandomListNode* node_clone_head = new RandomListNode(0);
			RandomListNode* front = pHead;
			RandomListNode* tmp = node_clone_head;
			RandomListNode* tmp1;
			while(front){
				tmp1 = front->next;
				front = tmp1->next;
				tmp1->next = NULL;
				tmp->next = tmp1;
				tmp = tmp->next;
			} 
			node_clone_head = node_clone_head->next;
			return node_clone_head;
		}
};

RandomListNode* Find(RandomListNode* head,int k)
{
	if(head == NULL){
		return NULL;
	}
	RandomListNode* tmp = head;
	while(tmp){
		cout<<"====="<<endl;
		cout<<tmp->label<<" "<<k<<endl;
		cout<<"====="<<endl;
		if(tmp->label == k){
			cout<<"Find"<<endl;
			break;
		}
		tmp = tmp->next;
	}
	return tmp;
}

int main()
{
	int n,val;
	while(cin>>n){
		RandomListNode* head = new RandomListNode(0);
		RandomListNode* tmp = head;
		for(int i = 0 ; i < n ; i++){
			cin>>val;
			RandomListNode* node = new RandomListNode(val);
			tmp->next = node;
			tmp = tmp->next;
		}
		head = head->next;
		tmp = head; 
		RandomListNode* tmp1 = head; 
		for(int i = 0 ; i < n ; i++){
			cin>>val;
			if(val != -1){
				RandomListNode* _random = Find(tmp1,val);
				tmp->random = _random;
			}
			tmp= tmp->next;
		}
		tmp = head;
		while(tmp){
			cout<<tmp->label<<" ";
			tmp = tmp->next;
		}
		tmp = head;
		while(tmp){
			if(tmp->random == NULL){
				cout<<"#"<<" ";
			}else{
				cout<<tmp->random->label<<" ";
			}
			tmp = tmp->next;
		}
		cout<<endl;
		Solution s;
		RandomListNode* clone = s.Clone(head);
		tmp = clone;
		while(tmp){
			cout<<tmp->label<<" ";
			tmp = tmp->next;
		}
		tmp = clone;
		while(tmp){
			if(tmp->random == NULL){
				cout<<"#"<<" ";
			}else{
				cout<<tmp->random->label<<" ";
			}
			tmp = tmp->next;
		}
	}
	
	return 0;
 } 
