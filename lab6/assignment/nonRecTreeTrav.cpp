#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct BTNode {
    char data;
    int loc;
    struct BTNode *right;
    struct BTNode *left;
};

class binTree {
    struct BTNode *start;
    
    public:
        void genTree(string);
        void printInOrder();
        //void printInOrder(struct BTNode *n);
        void printPreOrder();
        //void printInOrder(struct BTNode *n);
        void printPostOrder();
};

void binTree :: genTree(string c) {
    stack<struct BTNode*> s;
    struct BTNode *node;
    int j = 0;
    for(auto i = c.begin(); i < c.end(); i++) {
        node = new BTNode;
        if(*i != ' ') {
            node -> data = *i;
            node -> loc = j;
            j++;
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

void binTree :: printPreOrder() {
    /*if(start == NULL) return;
    if(start -> left != NULL) printInOrder(start -> left);
    printf("%c ", start -> data);
    if(start -> right != NULL) printInOrder(start -> right);*/
    struct BTNode *p = start;
    stack<struct BTNode*> z;
    if(p != NULL) z.push(p);
    while(!z.empty()) {
        p = z.top();
        z.pop();
        if(p -> right != NULL) z.push(p -> right);
        if(p -> left != NULL) z.push(p -> left);
        printf("%c ", p -> data); 
    }
}

/*void binTree :: printInOrder(struct BTNode *n) {
    if(n == NULL) return;
    if(n -> left != NULL) printInOrder(n -> left);
    printf("%c ", n -> data);
    if(n -> right != NULL) printInOrder(n -> right);
}*/

void binTree :: printInOrder() {
    stack<struct BTNode*> z;
    int a[1000] = {0};
    struct BTNode *p = start; 
    if(p != NULL) z.push(p);
    while(!z.empty()) {
        p = z.top();
        z.pop();
        if(a[p -> loc]) {
            printf("%c ", p -> data);
        }
        else {
            a[p -> loc]++;
            if(p -> right != NULL) z.push(p -> right);
            z.push(p);
            if(p -> left != NULL) z.push(p -> left);
        }
    } 
    return;
}

void binTree :: printPostOrder() {
    stack<struct BTNode*> z;
    int a[1000] = {0};
    struct BTNode *p = start; 
    if(p != NULL) z.push(p);
    while(!z.empty()) {
        p = z.top();
        if(a[p -> loc]) {
            printf("%c ", p -> data);
            z.pop();
        }
        else {
            a[p -> loc]++;
            if(p -> right != NULL) z.push(p -> right);
            if(p -> left != NULL) z.push(p -> left);
        }
    } 
    return;
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