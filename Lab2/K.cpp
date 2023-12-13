#include <bits/stdc++.h>
#define ll long long int
using namespace std;
	
struct Node{
	char letter;
	Node* next;
};	

Node* head = nullptr;

void insert(char z){
	Node* newNode = new Node();
    newNode->letter = z;
    newNode->next = nullptr;
    
    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}	

void printlist(){
	Node* current = head;
	map <char, int> m;
	queue <char> q;
	
	while (current){
		m[current->letter]++;
		q.push(current->letter);
		
		while (!q.empty() and m[q.front()] > 1){
			q.pop();
		}
		
		if (!q.empty()){
			cout << q.front() << ' ';
		}else {
			cout << "-1 ";
		}
		current = current->next;
	}
}
int main(){
	int x;
	cin >> x;
	
	for(int i = 0; i < x; i++){
		int y;
		cin >> y;
		for (int j = 0; j < y; j++){
			char z;
			cin >> z;
			insert(z);
		}
		printlist();
		cout << endl;
		
		Node* current;
		while (head){
			current = head;
			head = head->next;
			delete current;
		}
	}
}