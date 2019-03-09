//This program calculates number of possible entering permutations which will create the same binary tree.

#include<iostream>
#include<bits/stdc++.h>

int comb[101][101] = {0};

using namespace std;

struct BSTNode {            //Binary search tree node
    int data;               //Data
    struct BSTNode *right;  //right child ptr
    struct BSTNode *left;   //left child ptr
    int count;              //count of the elements been encountered
    int lSize;
    int rSize;
};

class BST {
    struct BSTNode *start;

    void insertEl(int, struct BSTNode*&);
    long long int perm(struct BSTNode*);

    public:
    BST();
    long long int perm();
    void insertEl(int);
};

BST :: BST() {
    start = NULL;
}

long long int BST :: perm() {
    if(start == NULL) return 1;
    if(start -> left != NULL && start -> right != NULL) return comb[start -> rSize + start -> lSize][start -> rSize] * perm(start -> right) * perm(start -> left);
    else if(start -> left == NULL && start -> right != NULL) return perm(start -> right);
    else if(start -> left != NULL && start -> right == NULL) return perm(start -> left);
    else if(start -> left == NULL && start -> right == NULL) return 1;
    return 1;
}

long long int BST :: perm(struct BSTNode *z) {
    if(z == NULL) return 1;
    if(z -> left != NULL && z -> right != NULL) return comb[z -> rSize + z -> lSize][z -> rSize] * perm(z -> right) * perm(z -> left);
    else if(z -> left == NULL && z -> right != NULL) return perm(z -> right);
    else if(z -> left != NULL && z -> right == NULL) return perm(z -> left);
    else if(z -> left == NULL && z -> right == NULL) return 1;
    return 1;
}

void BST :: insertEl(int i) {
    if(start == NULL) {         //if it was start was NULL new tree node was created and initialized and data was inserted
        start = new BSTNode;
        start -> right = NULL;
        start -> left = NULL;
        start -> data = i;
        start -> count = 1;
        start -> lSize = 0;
        start -> rSize = 0;
    }
    else {
        if(i > start -> data) {     //if i was greater than start node right node was called
            insertEl(i, start -> right);
            start -> rSize++;
        }
        else if(i < start -> data) {    //if i was lesser than start node, left node was called.
            insertEl(i, start -> left);
            start -> lSize++;
        }
        else start -> count++;
    }
}

void BST :: insertEl(int i, struct BSTNode*&p) {
    if(p == NULL) {         //if p was NULL new tree node was created and initialized and data was inserted
        struct BSTNode *q = new BSTNode;
        q = new BSTNode;
        q -> right = NULL;
        q -> left = NULL;
        q -> data = i;
        q -> count = 1;
        q -> rSize = 0;
        q -> lSize = 0;
        p = q;
    }
    else {
        if(i > p -> data) {     //if i was greater than p node right node was called
            insertEl(i, p -> right);
            p -> rSize++;
        }
        else if(i < p -> data) {    //if i was lesser than p node, left node was called.
            insertEl(i, p -> left);
            p -> lSize++;
        }
        else p -> count++;
    }
}

int main() {
    int k;
    scanf("%d", &k);
    void createComb(int, int);
    for(int i = 1; i <= 100; i++) {
        for(int j = 0; j <= i; j++) {
            createComb(i, j);
        }
    }
    while(k--) {
        int n;
        BST A;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            int l;
            scanf("%d", &l);
            A.insertEl(l);
        }
        long long int perm(struct BSTNode*);
        long long int p = A.perm();
        printf("%lld\n", p);
    }
    return 0;
}

void createComb(int i, int j) {
    if(j == 0) comb[i][j] = 1;
    else if(j == i) comb[i][j] = 1;
    else if(j == 1) comb[i][j] = i;
    else comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
}