//This code creates a Binary Search Tree and performs basic operations like insertion, search, finding the smallest element, pre-order traversal and in-order traversal on it.

#include<iostream>
#include<bits/stdc++.h>

struct BSTNode {                        //Binary search tree node
    int data;                           //Data of the node
    struct BSTNode *right;              //right child pointer
    struct BSTNode *left;               //left child pointer
    int count;                          //count of the elements been encountered
};

class BST {
    struct BSTNode *start;               //start of the tree


    void insertEl(int, struct BSTNode*&);//insertion function
    void searchEl(int, struct BSTNode*);//search function
    void smallest(struct BSTNode*);     //fn. to find the smallest element
    void preOrder(struct BSTNode*);     //pre-order traversal
    void inOrder(struct BSTNode*);      //in-order traversal


    public:
    BST();                              //class initializing function
    void insertEl(int);                 //wrapper for the function to insert an element
    void searchEl(int);                 //wrapper for the function to search
    void smallest();                    //wrapper for the function to return the smallest element
    void preOrder();                    //wrapper for the function to perform preOrder traversal
    void inOrder();                     //wrapper for the function to perform inOrder traversal
};

BST :: BST() {                          //class intializer, called when the class is declared
    start = NULL;                       //initializes start to NULL
}


void BST :: insertEl(int i) {           //wrapper definition for Insertion fn. with i as element to be added
    if(start == NULL) {                 //if start equals to NULL
        start = new BSTNode;            //create a new Node
        start -> right = NULL;          //define it's right and left child NULL 
        start -> left = NULL;       
        start -> data = i;              //store it's data as i
        start -> count = 1;             //# of times data occured equals to 1 
    }
    else {                              //if start doesn't equal to NULL
        if(i > start -> data) {         //if i is greater than current node data
            insertEl(i, start -> right);//recursive calling to go on right as i is greater than current element
        }  
        else if(i < start -> data) {    //if i is less than current node data
            insertEl(i, start -> left); //recursive calling to go on left as i is less than current element
        }
        else start -> count++;          //if i equals current element then counter increased by 1
    }
}

void BST :: insertEl(int i, struct BSTNode*&p) {    //working insertion fn. with p as the address of pointer to the passed node 
    if(p == NULL) {
        struct BSTNode *q = new BSTNode;
        q -> right = NULL;
        q -> left = NULL;
        q -> data = i;
        q -> count = 1;
        p = q;
    }
    else {
        if(i > p -> data) {
            insertEl(i, p -> right);
        }
        else if(i < p -> data) {
            insertEl(i, p -> left);
        }
        else p -> count++;
    }
}

void BST :: searchEl(int i) {           //wrapper fn. to search i in the tree
    if(start == NULL) printf("%d\n", 0);    //if start equals to NULL then element never existed in the tree
    else {
        if(i == start -> data) printf("%d\n", 1);   //checking whether element equals to the current element, if yes then printing 1
        else if(i > start -> data) searchEl(i, start -> right); //if i is greater than current element recursive call to right of the tree
        else searchEl(i, start -> left);    //if i is less than current element recursive call to left of the tree
    }
}

void BST :: searchEl(int i, struct BSTNode *p) {    //working search fn. with i as element and p as current node
    if(p == NULL) printf("%d\n", 0);
    else {
        if(i == p -> data) printf("%d\n", 1);
        else if(i > p -> data) searchEl(i, p -> right);
        else searchEl(i, p -> left);
    }
}

void BST :: smallest() {        //wrapper fn. to find the smallest element
    if(start == NULL) return;   //if start equals to NULL then tree is empty
    else {
        if(start -> left == NULL) printf("%d\n", start -> data);    //if left of the start is NULL then start is the smallest element
        else smallest(start -> left);   //if left exist then there exist a smaller element on the left of start, which will be on the extreme left node
    }
}

void BST :: smallest(struct BSTNode *p) {   //working fn. to find smallest element with p as current node
    if(p == NULL) return;                   //caution condition by chance node entered is NULL
    else {
        if(p -> left == NULL) printf("%d\n", p -> data);
        else smallest(p -> left);
    }
}

void BST :: inOrder() {             //wrapper fn. to in-order traversal
        if(start == NULL) return;   //if start is NULL return cause there is nothing to print
        if(start -> left != NULL) inOrder(start -> left);   //recursive call to go on left and print it's element if left isn't NULL
        printf("%d ", start -> data);                       // printing the current element
        if(start -> right != NULL) inOrder(start -> right); //recursive call to go on right and print it's element
}

void BST :: inOrder(struct BSTNode *p) {    //working fn. of in-order traversal with p as current node, traversal as: left -> current -> right
    if(p == NULL) return;                   //caution if it enters a NULL node
    if(p -> left != NULL) inOrder(p -> left);
    printf("%d ", p -> data);
    if(p -> right != NULL) inOrder(p -> right);
}

void BST :: preOrder() {                    //wrapper fn. to pre-order traversal
        if(start == NULL) return;           //if start is NULL return cause there is nothing to print
        printf("%d ", start -> data);       //print current element
        if(start -> left != NULL) preOrder(start -> left);      //recursive call to go on left and print it's element if left isn't NULL
        if(start -> right != NULL) preOrder(start -> right);    //recursive call to go on right and print it's element if left isn't NULL
}

void BST :: preOrder(struct BSTNode *p) {   //working fn. to pre-order traversal with p as pointer to current node, traversal as: current -> left -> right 
    if(p == NULL) return;                   //caution in case NULL pointer is called
    printf("%d ", p -> data);
    if(p -> left != NULL) preOrder(p -> left);
    if(p -> right != NULL) preOrder(p -> right);
}

int main() {                        //main fn.
    int t;                          //number of operations
    scanf("%d", &t);
    BST A;                          //declairing the Tree
    while(t--) {                    //running the while loop for t times
        int n;                      // type of operation
        scanf("%d", &n);
        switch(n) {                 //switch for operation
            case 1: {               //case 1, insertion of element l
                int l;              //element l
                scanf("%d", &l);
                A.insertEl(l);
                break;
            }
            case 2: {           //case 2, search for element l
                int l;          //element l
                scanf("%d", &l);
                A.searchEl(l);
                break;
            }
            case 3: {           //case 3, finding the smallest element
                A.smallest();
                //puts(" ");
                break;
            }
            case 4: {           //case 4, pre-order Traversal
                A.preOrder();
                puts(" ");
                break;
            }
            case 5: {           //case 5, in-order traversal
                A.inOrder();
                puts(" ");
                break;
            }
            default: break;     //default to break
        }
    }
    return 0;
}