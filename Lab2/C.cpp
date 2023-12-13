#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Node {
public:
    int value;
    Node* next;
    
    Node(int val) : value(val), next(nullptr) {}
};
Node* head = nullptr;

void insert(int y){
	Node* newNode = new Node(y);
	if (!head){
		head = newNode;
		return;
	}
	
	Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void posoutput(){
	int currentpos = 1;
	Node* current = head;
	
	while (current) {
        if (currentpos % 2 != 0) {
            cout << current->value << ' ';
        }
        current = current->next;
        currentpos++;
    }
}
int main(){
	int x;
	cin >> x;
	
	for (int i = 1; i <= x; i++){
		int y;
		cin >> y;
		insert(y);
	}		
	
	posoutput();
return 0;
}
