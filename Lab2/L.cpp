#include <bits/stdc++.h>
#define ll long long int
using namespace std;

struct Node {
  int val;
  Node *next;
 
  Node() {
    val = 0;
    next = NULL;
  }
 
};
 
int findMaxSum(int n, Node *head) {
	int sum1 = -1e9, sum2 = 0;
	Node* newNode = head;
	
	while(newNode){
		sum2 += newNode->val;
		
		if (sum2 > sum1){
			sum1 = sum2;
		}
		
		if (sum2 < 0){
			sum2 = 0;
		}
		
		newNode = newNode->next;
	}
	
	return sum1;
 
}
 
int main() {
  int x;
  cin >> x;
 
  Node *head, *tail;
  for (int i = 1; i <= x; ++i) {
    int y;
    cin >> y;
    Node *cur = new Node();
    cur -> val = y;
 
    if (i == 1) {
      head = tail = cur;
    } else {
      tail -> next = cur;
      tail = cur;
    }
  }
 
  cout << findMaxSum(x, head);
  return 0;
}
 
