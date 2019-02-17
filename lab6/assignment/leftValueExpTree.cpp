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
    int maxLoc;

    public:
        void genTree(string);
        void printLeftView();
        void printLeftView(struct BTNode*, int);
        void printInOrder();
        void printInOrder(struct BTNode *n);
};

void binTree :: genTree(string c) {
    stack<struct BTNode*> s;
    maxLoc = 0;
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

void binTree :: printLeftView() {
    if(start == NULL) return;
    if(maxLoc == 0) printf("%c ", start -> data);
    if(start -> left != NULL) printLeftView(start -> left, 1);
    if(start -> right != NULL) printLeftView(start -> right, 1);
}

void binTree :: printLeftView(struct BTNode *n, int p) {
    if(n == NULL) return;
    if(p > maxLoc) {
        printf("%c ", n -> data);
        maxLoc = p;
    }
    if(n -> left != NULL) printLeftView(n -> left, p + 1);
    if(n -> right != NULL) printLeftView(n -> right, p + 1);
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
        //f.printInOrder();
        //puts("");
        f.printLeftView();
        puts("");
    }
}