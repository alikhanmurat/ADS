#include <bits/stdc++.h>
#define ll long long int
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* node, int z) {
    if (node == nullptr) {
        return new Node(z);
    }

    if (z < node->value) {
        node->left = insert(node->left, z);
    } else {
        node->right = insert(node->right, z);
    }

    return node;
}
void printSubTree(Node* node){
	if (node == nullptr){
        return;
    }
	
	cout << node->value << " ";
    printSubTree(node->left);
    printSubTree(node->right);
	
	
}
int main() {
    int x, y;
    cin >> x;

    Node* root = nullptr;

    for (int i = 0; i < x; i++) {
        int z;
        cin >> z;
        root = insert(root, z);
    }
	cin >> y;
	Node* subtree = root;
	
	while (subtree != NULL and subtree->value != y){
		if (y < subtree->value){
			subtree = subtree->left;
		}else {
			subtree = subtree->right;
		}
	}
	
	printSubTree(subtree);
    return 0;
}
