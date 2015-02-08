#include <iostream>
#include <list>
#include <fstream>
using namespace std;

class trie_node {
	char key;
	string word;
	list <trie_node *> children;
	bool is_end;

public:

	trie_node (char k, string w) : key(k), word(w) { is_end = true; }
	trie_node (char k) : key(k) { is_end = false; }

	string get_word() {
		return word;
	}

	char get_key() {
		return key;
	}

	trie_node *insert_child(char child_key) {
		list <trie_node*>::iterator it;
		trie_node *temp;
		for (it = children.begin(); it != children.end(); it++) {
			temp = *it;
			if (child_key == temp->get_key())
				return *it;
			if (child_key < temp->get_key())
				break;
		}
		trie_node *child = new trie_node(child_key);
		children.insert(it, child);
		return child;
	}

	trie_node *get_child(char child_key) {
		for (auto child : children) {
			if (child->get_key() == child_key)
				return child;
		}
		return NULL;
	}

	void print_inorder() {
		if (is_end)
			cout << word << "\n";
		for (auto child : children)
			child->print_inorder();
	}

	void insert_word(string s, int char_index) {
		if (s.length() == char_index) {
			is_end = true;
			word = s;
			return;
		}
		trie_node *child = get_child(s[char_index]);
		if (!child)
			child = insert_child(s[char_index]);
		child->insert_word(s, char_index + 1);
	}

	bool lookup_word(string w, int char_index) {
		cout << char_index << " : " << w[char_index] << "\n";
		if (w.length() == char_index)
			return is_end;
		trie_node *child = get_child(w[char_index]);
		if (!child)	return false;
		return child->lookup_word(w, char_index + 1);
	}
};

class trie {
	trie_node *root;
	int word_count;

public:
	trie () {
		root = new trie_node(0);
		word_count = 0;
	}

	bool empty() {
		return (word_count == 0);
	}

	int get_word_count() {
		return word_count;
	}

	void insert_word(string word) {
		if (!word.empty()) {
			root->insert_word(word, 0);
			word_count++;
		}
	}

	bool lookup_word(string word) {
		if (!word.empty())
			return root->lookup_word(word, 0);
		return false;
	}

	void print_words() {
		root->print_inorder();
	}
};

int main(void) {
	trie T;
	ifstream f;
	f.open("words.txt");
	string word;
	while (getline(f, word))
		T.insert_word(word);
	cout << "No of words in dictionary: " << T.get_word_count() << "\n";
	while (getline(cin, word))
		cout << T.lookup_word(word) << "\n";
	f.close();
}
