#include <bits/stdc++.h>
#define ll long long int
using namespace std;

struct Node{
	int value;
	Node* next;
	Node* prev;	
	
	Node(int _value){
		prev = NULL;
		next = NULL;
		value = _value;
	}
};
Node* head = nullptr;
Node* tail = nullptr;

void insert(int w){
	Node* newNode = new Node(w);
	newNode->next = nullptr;
	
	if (!head){
		head = newNode;
		return;	
	}
	
	Node* temp = head;
	while (temp->next){
		temp = temp->next;
	}
	temp->next = newNode;
}

void posinsert(int y, int z){
	Node* newNode = new Node(y);
	newNode->next = NULL;
	
	if (z == 0){
		newNode->next = head;
		head = newNode;
	}else{
		Node* temp = head;
		while (z > 1){
			temp = temp->next;
			z--;
		}
		
		newNode->next = temp->next;
		temp->next = newNode;
	}
}

void printlist(){
	Node* current = head;
	while(current){
		cout << current->value << ' ';
		current = current->next;
	}
}
int main(){
	int x, y, z;
	cin >> x;
	
	for (int i = 0; i < x; i++){
		int w;
		cin >> w;
		insert(w);
	}
	
	cin >> y >> z;
	
	posinsert(y, z);
	printlist();
return 0;
}
