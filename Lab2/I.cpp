#include <bits/stdc++.h>
#define ll long long int
using namespace std;

struct Node{
	
	string val;
	Node * prev;
	Node * next;
	Node(string _val){
		prev = NULL;
		next = NULL;
		val = _val;
	}	
};

Node * head = nullptr;
Node * tail = nullptr;
int cnt = 0;

void add_back(string s){
	Node* newNode = new Node(s);
	if (!tail){
		tail = newNode;
		head = newNode;
		cnt++;
	}else{
		tail->next = newNode;
		tail = newNode;
		cnt++;
	}
}
void add_front(string s){
	Node* newNode = new Node(s);
	if (!head){
		head = newNode;
		tail = newNode;
		cnt++;
	}else{
		head->prev = newNode;
		head = newNode;
		cnt++;
	}
}
bool empty(){
	return cnt == 0;
}
void erase_front() { 
	if (cnt == 1){
    	head = tail;
	}
    Node* current = head;
    head = head->next;
    if (head) {
		head->prev = nullptr;
    }
    
    
    delete current;
    cnt--;
}
void erase_back() {
	if (cnt == 1){
    	tail = head;
	}
    Node* current = tail;
    tail = tail->prev;
    if (tail) {
        tail->next = nullptr;
    }
	
    
    delete current;
    cnt--;
}
string front() {
	if (cnt == 1){
		return tail->val;
	}
	return head->val;
}
string back() {
	if (cnt == 1){
		return head->val;
	}
    return tail->val;
}
void clear(){
	if (cnt == 0){
		return;
	}
	Node* current = head;
	Node* next;
	
	while (current){
		next = current->next;
		delete current;
		current = next;
	}
	cnt = 0;
}
  
int main()
{
	string s;
   	while(cin >> s){
   		if(s == "add_front"){
   			string t;
   			cin >> t;
   			add_front(t);
   			cout << "ok" << endl;
   		}
   		if(s == "add_back"){
   			string t;
   			cin >> t;
   			add_back(t);
   			cout << "ok" << endl;
   		}
   		if(s == "erase_front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << front() << endl;
   				erase_front();
   			}
   		}
   		if(s == "erase_back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl;
   				erase_back();
   			}
   		}
   		if(s == "front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << front() << endl;
   			}
   		}
   		if(s == "back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl;
   			}
   		}
   		if(s == "clear"){
   			clear();
   			cout << "ok" << endl;
   		}
   		if(s == "exit"){
   			cout << "goodbye" << endl;
   			break;
   		}
   	}
    return 0;
}
