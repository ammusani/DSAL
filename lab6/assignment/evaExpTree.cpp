#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
#include<math.h>
using namespace std;

struct BTNode {
    int data;
    int isChar;
    struct BTNode *right;
    struct BTNode *left;
};

class binTree {
    struct BTNode *start;

    public:
        void genTree(char[]);
        void printInOrder();
        void printInOrder(struct BTNode*);
        long long int evaExp();
        long long int evaExp(struct BTNode*);
};

void binTree :: genTree(char c[]) {
    stack<struct BTNode*> s;
    struct BTNode *node;
    char *token = strtok(c, " ");
    int isnum = 0;
    if(token != NULL && (token[0] >= 48 && token[0] <= 57)) isnum = 1;
    while(token) {
        node = new BTNode;
        if(isnum) {
            node -> isChar = 0;
            sscanf(token, "%d", &(node -> data));
            node -> right = NULL;
            node -> left = NULL;
        }
        else {
            node -> isChar = 1;
            node -> data = (int)token[0];
            node -> right = s.top();
            s.pop();
            node -> left = s.top();
            s.pop();
        }
        s.push(node);
        token = strtok(NULL, " ");
        if(token != NULL && (token[0] >= 48 && token[0] <= 57)) isnum = 1;
        else isnum = 0;
        if(token == NULL) start = node;
    }
}

void binTree :: printInOrder() {
    if(start == NULL) return;
    if(start -> left != NULL) printInOrder(start -> left);
    if(start -> isChar) {
        printf("%c ", (char)start -> data);
    }
    else printf("%d ", start -> data);
    if(start -> right != NULL) printInOrder(start -> right);
}

void binTree :: printInOrder(struct BTNode *n) {
    if(n == NULL) return;
    if(n -> left != NULL) printInOrder(n -> left);
    if(n -> isChar) {
        printf("%c ", (char)n -> data);
    }
    else printf("%d ", n -> data);
    if(n -> right != NULL) printInOrder(n -> right);
}

long long int binTree :: evaExp() {
    if(start == NULL) return 0;
    if(start -> isChar) {
        long int x;
        long int y;
        if(start -> left != NULL) x = evaExp(start -> left);
        if(start -> right != NULL) y = evaExp(start -> right);
        switch((char)start -> data) {
            case '+': {
                return x + y;
            }
            case '-': {
                return x - y;
            }
            case '*': {
                return x * y;
            }
            case '/': {
                return x / y;
            }
            case '^': {
                return (long long int)pow(x, y);
            }
        }
    }
    else return start -> data;
    return 0;
}

long long int binTree :: evaExp(struct BTNode *n) {
    if(n == NULL) return 0;
    if(n -> isChar) {
        long int x;
        long int y;
        if(n -> left != NULL) x = evaExp(n -> left);
        if(n -> right != NULL) y = evaExp(n -> right);
        switch((char)n -> data) {
            case '+': {
                return x + y;
            }
            case '-': {
                return x - y;
            }
            case '*': {
                return x * y;
            }
            case '/': {
                return x / y;
            }
            case '^': {
                return (long long int)pow(x, y);
            }
        }
    }
    else return n -> data;
    return 0;
}

int main() {
    int t;
    scanf("%d", &t);
    getchar();
    while(t--) {
        binTree f;
        char z[1000];
        cin.getline(z, 1000);
        //cout << z;
        f.genTree(z);
        //cout << z;
        //f.printInOrder();
        //puts("");
        long long int p = f.evaExp();
        printf("%lld\n", p);
        
    }
    return 0;
}