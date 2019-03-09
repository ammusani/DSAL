#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct node {
	int data;
	node *left;
    node *right;
    int inOrderVisited = 0;
};

class binaryTree {
	private:
		node *root;

        void inorder(struct node *p) {
            if(p == NULL) return;                   //caution if it enters a NULL node
            if(p -> left != NULL) inorder(p -> left);
            printf("%d ", p -> data);
            if(p -> right != NULL) inorder(p -> right);
        }

        void preorder(struct node *p) {
            if(p == NULL) return;
            printf("%d ", p -> data);
            if(p -> left != NULL) preorder(p -> left);
            if(p -> right != NULL) preorder(p -> right);
        }
	
	public:
		binaryTree() {
			root = NULL;
		}

		void createTree(int *input,int *randomInput,int total_nodes) {
			int j = 0;
			for(int i=0;i<total_nodes;i++) {
				insertNode(input[i],randomInput,&j);
			}
		}

		void insertNode(int key,int *randomInput, int *j) {
			node *temp = new node();
			temp->data = key;
			temp->right = NULL;
			temp->left = NULL;

			if(root!=NULL) {
				bool inserted = false;
				node *p = root;
				while(!(inserted)) {
					int currRandom = randomInput[*j];
					*j = *j + 1;

					if(currRandom == 0) {
						if(p->left == NULL) {
							p->left = temp;
							inserted = true;
						}
						else {
							p = p->left;
						}
					}
					else {
						if(p->right == NULL) {
							p->right = temp;
							inserted = true;
						}
						else {
							p = p->right;
						}
					}
				}	
			}	
			else {
				root = temp;
			}	
		}

		void toBST() {
			stack<struct node*> s;
            struct node *p = root;
            vector<int> v;

            if(p != NULL) s.push(p);
            
            while(!s.empty()) {
                p = s.top();
                s.pop();
                v.push_back(p -> data);
                if(p -> right != NULL) s.push(p -> right);
                if(p -> left != NULL) s.push(p -> left);
            }

            sort(v.begin(), v.end());

            p = root;
            if(p != NULL) s.push(p);

            vector<int> :: iterator ptr;
            ptr = v.begin();

            while(!s.empty()) {
                p = s.top();
                s.pop();
                if(p -> inOrderVisited == 1) {
                    p -> data = *ptr;
                    ptr++;
                    p -> inOrderVisited = 0;
                }
                else {
                    if(p -> right != NULL) s.push(p -> right);
                    p -> inOrderVisited = 1;
                    s.push(p);
                    if(p -> left != NULL) s.push(p -> left);
                }
            }
		}
		void inorder() {
			if(root == NULL) return;   //if start is NULL return cause there is nothing to print
            if(root -> left != NULL) inorder(root -> left);   //recursive call to go on left and print it's element if left isn't NULL
            printf("%d ", root -> data);                       // printing the current element
            if(root -> right != NULL) inorder(root -> right); //recursive call to go on right and print it's element
		}
		void preorder() {
			if(root == NULL) return;           //if start is NULL return cause there is nothing to print
            printf("%d ", root -> data);       //print current element
            if(root -> left != NULL) preorder(root -> left);      //recursive call to go on left and print it's element if left isn't NULL
            if(root -> right != NULL) preorder(root -> right);    //recursive call to go on right and print it's element if left isn't NULL
		}
};

int main() {
	binaryTree T;
	int total_nodes,seq_size,*input,*randomInput;
	cin>>total_nodes>>seq_size;

	input = (int*)malloc(sizeof(int)*total_nodes);
	randomInput = (int*)malloc(sizeof(int)*seq_size);

	for(int i=0;i<total_nodes;i++) {
		cin>>input[i];
	}

	for(int i=0;i<seq_size;i++) {
		cin>>randomInput[i];
	}

	T.createTree(input,randomInput,total_nodes);
	T.toBST();
	T.inorder();
    puts("");
	T.preorder();
    puts("");
    return 0;
}