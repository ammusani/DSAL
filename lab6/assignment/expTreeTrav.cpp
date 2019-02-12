#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct BTNode {
    char data;
    struct BTNode *right;
    struct BTNode *left;
};

class binTree {
    struct BTNode *start;
    
    public:
        void genTree(string);
        void printInOrder();
        void printInOrder(struct BTNode *n);
        void printPreOrder();
        void printPreOrder(struct BTNode *n);
        void printPostOrder();
        void printPostOrder(struct BTNode *n);
};

void binTree :: genTree(string c) {
    stack<struct BTNode*> s;
    struct BTNode *node;
    for(auto i = c.begin(); i < c.end(); i++) {
        node = new BTNode;
        if(*i != ' ') {
            node -> data = *i;
            switch(*i) {
                case '+':
                case '*':
                case '/':
                case '-':
                case '^': {
                    node -> right = s.top();
                    s.pop();
                    node -> left = s.top();
                    s.pop();
                    break;
                }
                default: {
                    node -> right = NULL;
                    node -> left = NULL;                
                    break;
                }
            }
            s.push(node);
            if(i == c.end() - 1) start = node;
        }
    }
}

void binTree :: printInOrder() {
    if(start == NULL) return;
    if(start -> left != NULL) printInOrder(start -> left);
    printf("%c ", start -> data);
    if(start -> right != NULL) printInOrder(start -> right);
}

void binTree :: printInOrder(struct BTNode *n) {
    if(n == NULL) return;
    if(n -> left != NULL) printInOrder(n -> left);
    printf("%c ", n -> data);
    if(n -> right != NULL) printInOrder(n -> right);
}

void binTree :: printPreOrder() {
    if(start == NULL) return;
    printf("%c ", start -> data);
    if(start -> left != NULL) printPreOrder(start -> left);
    if(start -> right != NULL) printPreOrder(start -> right);
}

void binTree :: printPreOrder(struct BTNode *n) {
    if(n == NULL) return;
    printf("%c ", n -> data);
    if(n -> left != NULL) printPreOrder(n -> left);
    if(n -> right != NULL) printPreOrder(n -> right);
}

void binTree :: printPostOrder() {
    if(start == NULL) return;
    if(start -> left != NULL) printPostOrder(start -> left);
    if(start -> right != NULL) printPostOrder(start -> right);
    printf("%c ", start -> data);
}

void binTree :: printPostOrder(struct BTNode *n) {
    if(n == NULL) return;
    if(n -> left != NULL) printPostOrder(n -> left);
    if(n -> right != NULL) printPostOrder(n -> right);
    printf("%c ", n -> data);
}

int main() {
    int t;
    scanf("%d", &t);
    getchar();
    while(t--) {
        binTree f;
        string z;
        getline(cin, z);
        //cout << z;
        f.genTree(z);
        //cout << z;
        f.printInOrder();
        puts("");
        f.printPreOrder();
        puts("");
        f.printPostOrder();
        puts("");
    }
    return 0;
}
