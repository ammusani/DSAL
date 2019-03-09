//This program inserts element x, finds ith largest and smallest element, inorder successor, inOrder predecessor and deletes an element x.

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct BSTNode {            //Binary search tree node
    int data;               //Data
    struct BSTNode *right;  //right child ptr
    struct BSTNode *left;   //left child ptr
    int count;              //count of the elements been encountered
    int size;
};

class BST {
    struct BSTNode *start;

    int largest(struct BSTNode*);        //fn. to find the largest element
    int smallest(struct BSTNode*);        //fn. to find the smallest element
    void insertEl(int, struct BSTNode*&); //insertion function
    void delEl(int, struct BSTNode*&);    //deletion function
    void inOrder(struct BSTNode*);          //inOrder traversal
    void ithLEl(int, struct BSTNode*);      //ith largest element
    void ithSEl(int, struct BSTNode*);      //ith smallest element
    void suc(int, int, struct BSTNode*);    //successor in inOrder
    void pre(int, int, struct BSTNode*);    //predecessor in inOrder

    public:
    BST();                                //constructor
    void insertEl(int);
    void delEl(int);
    void inOrder();
    void ithLEl(int);
    void ithSEl(int);
    void pre(int, int);
    void suc(int, int);
};

BST :: BST() {
    start = NULL;
}

void BST :: insertEl(int i) {
    if(start == NULL) {         //if it was start was NULL new tree node was created and initialized and data was inserted
        start = new BSTNode;
        start -> right = NULL;
        start -> left = NULL;
        start -> data = i;
        start -> count = 1;
        start -> size = 1;
    }
    else {
        start -> size++;
        if(i > start -> data) {     //if i was greater than start node right node was called
            insertEl(i, start -> right);
        }
        else if(i < start -> data) {    //if i was lesser than start node, left node was called.
            insertEl(i, start -> left);
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
        q -> size = 1;
        p = q;
    }
    else {
        p -> size++;
        if(i > p -> data) {     //if i was greater than p node right node was called
            insertEl(i, p -> right);
        }
        else if(i < p -> data) {    //if i was lesser than p node, left node was called.
            insertEl(i, p -> left);
        }
        else p -> count++;
    }
}

void BST :: delEl(int v) {              //wrapper to the delete function
    if(start == NULL) return;
    if(v > start -> data) {
        delEl(v, start -> right);
        start -> size--;
    }
    else if(v < start -> data) {
        delEl(v, start -> left);
        start -> size--;
    }
    else {
        if(start -> left == NULL && start -> right == NULL) {
            struct BSTNode *tmp = start;
            start = NULL;
            delete tmp;
        }
        else if(start -> left != NULL && start -> right == NULL) {
            struct BSTNode *tmp = start;
            start = start -> left;
            delete tmp;
        }
        else if(start -> left == NULL && start -> right != NULL) {
            struct BSTNode *tmp = start;
            start = start -> right;
            delete tmp;
        }
        else if(start -> left != NULL && start -> right != NULL) {
            int j = smallest(start -> right);
            start -> data = j;
            start -> size--;
            delEl(j, start -> right);
        }
    }
}

void BST :: delEl(int v, struct BSTNode *&z) {      //delete function
    if(z == NULL) return;
    if(v > z -> data) {
        delEl(v, z -> right);                       //right calling for deleting since element is greater than current
        z -> size--;
    }
    else if(v < z -> data) {
        delEl(v, z -> left);                        //left calling for deleting since element is lesser than current
        z -> size--;
    }
    else {
        if(z -> left == NULL && z -> right == NULL) {       //directly deleting the node since it's left and right both are NULL
            struct BSTNode *tmp = z;
            z = NULL;
            delete tmp;
        }
        else if(z -> left != NULL && z -> right == NULL) {  //assigning the current node pointer to left of it and deleting the current, as left exist and right is NULL
            struct BSTNode *tmp = z;
            z = z -> left;
            delete tmp;
        }
        else if(z -> left == NULL && z -> right != NULL) {  //assigning the current node pointer to right of it and deleting the current, as right exist and left is NULL
            struct BSTNode *tmp = z;
            z = z -> right;
            delete tmp;
        }
        else if(z -> left != NULL && z -> right != NULL) {  //since neither of the right or left are NULL replacing current with the smallest element on right and calling deletion function to delete the nodeof that element 
            int j = smallest(z -> right);
            z -> data = j;
            z -> size--;
            delEl(j, z -> right);
        }
    }
}

void BST :: ithSEl(int i) {             //wrapper to ith smallest element fn., finds the ith smallest element in the complete tree
    if(start == NULL) return;
    int k;
    if(start -> left != NULL) k = start -> left -> size;
    else k = 0;
    if(k + 1 == i) printf("%d\n", start -> data);
    else if(k >= i) ithSEl(i, start -> left);
    else if(i > k + 1) ithSEl(i - k - 1, start -> right);
}

void BST :: ithSEl(int i, struct BSTNode *p) {  //function finds the ith smallest element in the tree for which p is the node. NOTE: i is variable!!
    if(p == NULL) return;
    int k;
    if(p -> left != NULL) k = p -> left -> size;    //checking size of the left subtree of the tree
    else k = 0;
    if(k + 1 == i) printf("%d\n", p -> data);       //if i equals to left size plus one then current element is the element
    else if(k >= i) ithSEl(i, p -> left);           //if left size is greater than find it in left of the tree
    else if(i > k + 1) ithSEl(i - k - 1, p -> right);   //if left size plus one is smaller than i then element is in right of the tree, so call on the right with reducing left size plus one from the i so, whenever subtrees of right are searched they have to be lesser.
}

void BST :: ithLEl(int i) {             //wrapper to ith largest element func., finds the ith largest element in the complete tree
    if(start == NULL) return;
    int k;
    if(start -> right != NULL) k = start -> right -> size;
    else k = 0;
    if(k + 1 == i) printf("%d\n", start -> data);
    else if(k >= i) ithLEl(i, start -> right);
    else if(i > k + 1) ithLEl(i - k - 1, start -> left);
}

void BST :: ithLEl(int i, struct BSTNode *p) {  //function finds the ith largest element in the tree for which p is the node. NOTE: i is variable!!
    if(p == NULL) return;
    int k;
    if(p -> right != NULL) k = p -> right -> size;  //checking size of the right subtree of the tree
    else k = 0;
    if(k + 1 == i) printf("%d\n", p -> data);       //if i equals to right size plus one then current element is the element
    else if(k >= i) ithLEl(i, p -> right);          //if right size is greater then find it in right of the tree
    else if (i > k + 1) ithLEl(i - k - 1, p -> left);   //if right size plus one is smaller than i then element is in left of the tree, so call on the left with reducing right size plus one from the i so, whenever subtrees of left are searched they have to be lesser.
}

void BST :: suc(int i, int prev) {      //wrapper to function which will find successor of i
    if(start == NULL) return;
    if(start -> data == i) {
        if(start -> right != NULL) printf("%d\n", smallest(start -> right));
        else printf("%d\n", prev);
    }
    else if(i > start -> data) {
        if(start -> right != NULL) suc(i, prev, start -> right);
        else printf("%d\n", prev);
    }
    else if(i < start -> data) {
        if(start -> left != NULL) suc(i, start -> data, start -> left);
        else printf("%d\n", prev);
    }
}

void BST :: suc(int i, int prev, struct BSTNode *p) {   //finds the successor to the element i, prev is element where the last left turn was taken 
    if(p == NULL) return;
    if(p -> data == i) {
        if(p -> right != NULL) printf("%d\n", smallest(p -> right));    //if right of p isn't NULL successor will be the  smallest element in it's right
        else printf("%d\n", prev);                      //else prev element where a left turn was taken will be successor
    }
    else if(i > p -> data) {
        if(p -> right != NULL) suc(i, prev, p -> right);    //taking a right turn with same prev
        else printf("%d\n", prev);
    }
    else if(i < p -> data) {
        if(p -> left != NULL) suc(i, p -> data, p -> left); //taking a left turn with replacing prev with current data and calling the function recursively
        else printf("%d\n", prev);
    }
}

void BST :: pre(int i, int prev) {      //wrapper fn. to find predecessor of i
    if(start == NULL) return;
    if(start -> data == i) {
        if(start -> left != NULL) printf("%d\n", largest(start -> left));
        else printf("%d\n", prev);
    }
    else if(i > start -> data) {
        if(start -> right != NULL) pre(i, start -> data, start -> right);
        else printf("%d\n", prev);
    }
    else if(i < start -> data) {
        if(start -> left != NULL) pre(i, prev, start -> left);
        else printf("%d\n", prev);
    }
}

void BST :: pre(int i, int prev, struct BSTNode *p) {       //finds predecessor to element i, prev is the element where last right turn was taken
    if(p == NULL) return;
    if(p -> data == i) {
        if(p -> left != NULL) printf("%d\n", largest(p -> left));   //since left doesn't equal to NULL, the largest element in the left will be predecessor
        else printf("%d\n", prev);                                  //since left is NULL prev right turn would be the predecessor
    }
    else if(i > p -> data) {
        if(p -> right != NULL) pre(i, p -> data, p -> right);       //taking a right turn changing the value of prev with current's data
        else printf("%d\n", prev);
    }
    else if(i < p -> data) {
        if(p -> left != NULL) pre(i, prev, p -> left);              //taking a left turn, no change in prev
        else printf("%d\n", prev);
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

int BST :: smallest(struct BSTNode *p) {   //working fn. to find smallest element with p as current node
    if(p == NULL) return 0;                   //caution condition by chance node entered is NULL
    else {
        if(p -> left == NULL) return p -> data;
        else return smallest(p -> left);
    }
}

int BST :: largest(struct BSTNode *p) {   //working fn. to find largest element with p as current node
    if(p == NULL) return 0;                   //caution condition by chance node entered is NULL
    else {
        if(p -> right == NULL) return p -> data;
        else return largest(p -> right);
    }
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
            case 2: {       //case 2, ith largest element
                int l;
                scanf("%d", &l);
                A.ithLEl(l);
                break;
            }
            case 3: {       //case 3, ith smallest element
                int l;
                scanf("%d", &l);
                A.ithSEl(l);
                break;
            }
            case 4: {       //case 4, successor of element i
                int l;
                scanf("%d", &l);
                A.suc(l, -100);
                break;
            }
            case 5: {       //case 5, predecessor of element i
                int l;
                scanf("%d", &l);
                A.pre(l, -100);
                break;
            }
            case 7: {           //case 7, in-order traversal
                A.inOrder();
                puts(" ");
                break;
            }
            case 6: {       //case 6, delete an element
                int l;
                scanf("%d", &l);
                A.delEl(l);
                break;
            }
            default: break;     //default to break
        }
    }
    return 0;
}