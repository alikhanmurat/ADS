#include <bits/stdc++.h>
#define ll long long int
using namespace std;

struct Node {
  string word;
  Node* next;
  Node* prev;

  Node() {}

  Node(string word) {
    this->word = word;
    this->next = NULL;
  }
};


Node* shift(Node* head, int x, int y, Node* tail) {
    if(y > x){
        y = y % x;
    }
    
    int stop = 1;
    Node* temp = head;
    Node* current;
    while (y > 0 ){   
        if(stop == 1){
            current = temp;
        }
        temp = temp->next;
        y--;
    }
    current->next = NULL;
    tail->next = head;
    return temp;

}

void print(Node* head) {
	Node* cur = head;
  	while (cur != NULL) {
    	cout << cur->word << " ";
    	cur = cur->next;
  	}
  	cout << endl;
}

int main() {
	ll x, y; 
  	cin >> x >> y;
  	Node* head;
 	Node* current;
  	Node* tail;
  	
  	for (int i = 0; i < x; i++) {
    	string word; 
		cin >> word;
    	if (i == 0) {
      		head = new Node(word);
      		current = head;
    	}else {
      		current->next = new Node(word);
      		current = current->next;
            tail = current;
    	}
  	}

  	head = shift(head, x, y, tail);
    print(head);
}