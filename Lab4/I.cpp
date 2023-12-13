#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node *left;
    Node *right;
    int multiplicity;
    Node(int val){
        this->val = val;
        this->left = this->right = NULL;
        this->multiplicity = 1;
    }
};

struct BinSearchTree{
    Node* root;
    BinSearchTree() {
        root = NULL;
    }
private:
    Node* add(int x, Node *cur){
        if(!cur) cur = new Node(x);
        
        else if(x == cur->val){
            cur->multiplicity++;
            return cur;
        }
        else if (x < cur->val) cur->left = add(x, cur->left);
        else cur->right = add(x,cur->right);
        return cur;
    }
    int find(int x, Node *cur){
        if(cur == NULL) return 0;
        if(x == cur->val)
            return cur->multiplicity;

        else if(x < cur->val) return find(x, cur->left);
        else return find(x, cur->right);
    }
    int rightmost(Node *cur){
        if(cur == NULL) return -1;
        if(cur->right == NULL) return cur->val;
        return rightmost(cur->right);
    }
    Node *_delete(int x, Node *cur){
        if(cur == NULL) return NULL;
        
        if(x < cur->val)
            cur->left = _delete(x, cur->left);

        else if (x > cur->val){
            cur->right = _delete(x, cur->right);
        }
        else{
            if(cur->multiplicity != 0){
                cur->multiplicity--;
                return cur;
            }
            else{
                if(!cur->left && !cur->right){
                    delete cur;
                    return NULL;
                }
                else if(cur->left && !cur->right){
                    Node *temp = cur->left;
                    delete cur;
                    return temp;
                }
                else if(!cur->left && cur->right){
                    Node *temp = cur->right;
                    delete cur;
                    return temp;
                } 
                else if(cur->left && cur->right){
                    cur->val = rightmost(cur->left);
                    cur->left = _delete(cur->val, cur->left);
                }
            }
        }
        return cur;
    }
    

public:
    void add(int x){
        this->root = add(x, root);
    }

    int getCnt(int x){
        return find(x, root);
    }

    void del(int x){
        this->root = _delete(x, root);
    }

};


int main() {
    int x;
    cin >> x;
    BinSearchTree tree;
    
    for (int i = 0; i < x; i++) {
        string s; int y;
        cin >> s >> y;
        if(s == "insert"){
            tree.add(y);
        }
        else if(s == "cnt"){
            cout << tree.getCnt(y) << endl;
        }
        else{
            tree.del(y);
        }
    }

    return 0;
}
