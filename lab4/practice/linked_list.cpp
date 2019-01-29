#include<iostream>
using namespace std;

struct node {
    int data;
    struct node* next;
};

class List {
    struct node* head;
    struct node* last;
    int count = 0;
    public:
        List() {
            head = new node;
            last = head;
            //printf("%d", 9);
            head -> next = NULL;
        } 
        void insert(int value);
        void print();
        //void del(int k);
        //int isEmpty();
};

void List :: insert(int value) {
    struct node* q = new node;
    q -> next = NULL;
    q -> data = value;
    last -> next = q;
    last = q;
    count++;
    //printf("%d\n", count);
}

void List :: print() {
    struct node* p = head;
    for(int i = 0; i < count; i++) {
        p = p -> next;
        printf("%d ", p -> data);
    }
    puts("");
}

int main() {
    int t;
    scanf("%d", &t);
    int n;
    int k;
    while(t--) {
        scanf("%d", &n);
        List a;
        for(int i = 1; i <= n; i++) {
            scanf("%d", &k);
            a.insert(k);
        }
        a.print();
    }
}
