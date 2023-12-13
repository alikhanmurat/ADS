#include <bits/stdc++.h>

using namespace std;

struct node {
    int val;
    node *left;
    node *right;
    node(int val) : val(val), left(nullptr), right(nullptr) {}
};

struct bst {
    node *root;
    bst() : root(nullptr) {}

    void add(int x) {
        root = insert(root, x);
    }

    node *insert(node *current, int x) {
        if (current == nullptr) {
            return new node(x);
        }
        if (x < current->val) {
            current->left = insert(current->left, x);
        } else if (x > current->val) {
            current->right = insert(current->right, x);
        }
        return current;
    }

    void print(node *current) {
        if (current != nullptr) {
            cout << current->val << " ";
            print(current->left);
            print(current->right);
        }
    }

    node *balance(vector<node *> &v, int start, int end) {
        if (start > end) return nullptr;
        int mid = start + (end - start) / 2;
        node *root = v[mid];

        root->left = balance(v, start, mid - 1);
        root->right = balance(v, mid + 1, end);

        return root;
    }

    node *ans() {
        vector<node *> v;
        store(root, v);
        return balance(v, 0, v.size() - 1);
    }

    void store(node *current, vector<node *> &v) {
        if (current == nullptr) return;
        store(current->left, v);
        v.push_back(current);
        store(current->right, v);
    }
};

int main() {
    int x;
    cin >> x;
    int y = pow(2, x) - 1;
    int a[y];

    for (int i = 0; i < y; i++) {
        cin >> a[i];
    }

    bst b;

    for (int i = 0; i < y; ++i) {
        b.add(a[i]);
    }

    node *res = b.ans();

    b.print(res);

    return 0;
}