#include <iostream>
using namespace std;

class List {
	int key;
	List *next;
public:
	List () : key(0), next(NULL) {}
	List (int k) : key(k), next(NULL) {}
	List (int k, List *n) : key(k), next(n) {}
	int size(void) {
		if (!this->next)	return 1;
		return this->next->size() + 1;
	}
	void push(int x) {
		List *new_node = new List(key, next);
		key = x;
		next = new_node;
	}
};

int main(void) {
	List l (10);
	l.push(2);
	l.push(3);
	cout << l.size() << endl;
	return 0;
}
