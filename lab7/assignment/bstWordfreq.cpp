//The program stores the frequency of words in a sentence and prints it in a dictionary order

#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

struct BSTNode {                        //Binary search tree node
    string data;                           //Data of the node
    struct BSTNode *right;              //right child pointer
    struct BSTNode *left;               //left child pointer
    int count;                          //count of the elements been encountered
};

class BST {
    struct BSTNode *start;               //start of the tree


    void insertEl(string, struct BSTNode*&);//insertion function
    void inOrder(struct BSTNode*);      //in-order traversal


    public:
    BST();                              //class initializing function
    void insertEl(string);                 //wrapper for the function to insert an element
    void inOrder();                     //wrapper for the function to perform inOrder traversal
};

void BST :: insertEl(string i) {           //wrapper definition for Insertion fn. with i as element to be added
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

void BST :: insertEl(string i, struct BSTNode*&p) {    //working insertion fn. with p as the address of pointer to the passed node 
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

BST :: BST() {
    start = NULL;
}

void BST :: inOrder() {             //wrapper fn. to in-order traversal
        if(start == NULL) return;   //if start is NULL return cause there is nothing to print
        if(start -> left != NULL) inOrder(start -> left);   //recursive call to go on left and print it's element if left isn't NULL
        cout << start -> data << ' ' << start -> count << endl;                       // printing the current element
        if(start -> right != NULL) inOrder(start -> right); //recursive call to go on right and print it's element
}

void BST :: inOrder(struct BSTNode *p) {    //working fn. of in-order traversal with p as current node, traversal as: left -> current -> right
    if(p == NULL) return;                   //caution if it enters a NULL node
    if(p -> left != NULL) inOrder(p -> left);
    cout << p -> data << ' ' << p -> count << endl;
    if(p -> right != NULL) inOrder(p -> right);
}

int main() {                                //main fn.
    int t;                                  //number of cases
    scanf("%d", &t);
    getchar();                              //clearing the buffer from '\n'
    while(t--) {
        char z[1000];                       //character array
        BST A;                              //the tree
        cin.getline(z, 1000);               //taking string input
        char *token = strtok(z, " ");       //generating a token, i.e. the 1st word in the string
        while(token) {                      //while the nth string isn't NULL
            string str;
            str = token;                    //typecasting a char array to string    
            A.insertEl(str);                //inserting in into A
            token = strtok(NULL, " ");      //getting the (n + 1)th string
        }
        A.inOrder();                        //In-order printing of A
        puts(" ");                          //Newline
    }
    return 0;
}