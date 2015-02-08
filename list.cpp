#include <iostream>
using namespace std;

struct ListNode {
	int key;
	ListNode *next;
	ListNode () : key(0), next(NULL) {}
	ListNode (int k): key(k), next(NULL) {}
};

class List {
	ListNode *head;
public:
	ListNode (): head(NULL) {}
	int size(void) {
		ListNode *temp = head;
		int s = 0;
		while(temp) {
			temp = temp->next;
			s++;
		}
		return s;
	}
	void push(int index, int key) {
		ListNode *temp = head;
		ListNode *new_node = new ListNode(key);
		if (index == 0) {
			new_node->next = head;
			head = new_node;
			return;
		}
		int s = 0;
		while((s < index - 1) && temp) {
			temp = temp->next;
			s++;
		}
		if (!temp) {
			cout << __func__ << ": invalid index\n";
			return;
		}
		new_node->next = temp->next;
		temp->next = new_node;
	}
	int pop(int index) {
		if (this->size() == 0)
		if (index == 0) {




