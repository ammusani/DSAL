#include<iostream>
#include<string.h>
using namespace std;

struct node {
    int data;
    struct node* next;
};

class bigInt {
    struct node *head;
    struct node *last;
    int len;
    public:
        bigInt();
        void insertL(char);
        void insertH(int);
        //int value();
        int length();
        bigInt operator +(bigInt);
        void print();
        struct node **getHead();
};

bigInt :: bigInt() {
    head = new node;
    last = head;
    head -> next = NULL;
    len = 0;
}

void bigInt :: insertL(char c) {
    struct node *q;
    q = new node;
    q -> next = NULL;
    q -> data = (int)c - 48;
    last -> next = q;
    last = q;
    len++;
}

void bigInt :: insertH(int p) {
    struct node *r = new node;
    r -> next = head -> next;
    head -> next = r;
    r -> data = p;
    len++;
}

int bigInt :: length() {
    return len;
}

void bigInt :: print() {
    struct node *p;
    p = head -> next;
    while(p -> next != NULL) {
        printf("%d", p -> data);
        p = p -> next;
    }
    printf("%d", p -> data);
}

struct node **bigInt :: getHead() {
    return &(head -> next);
}

bigInt bigInt:: operator +(bigInt p) {
        int carry = 0;
        int sum;
        bigInt r;
        struct node *j;
        j = head -> next;
        struct node **k;
        k = p.getHead();
        struct node *q;
        q = *k;
        int m;
        int n;
        while(j != NULL) {
            m = j -> data;
            if(q == NULL) n = 0;
            else n = (q->data);
            sum = m + n + carry;
            carry = sum / 10;
            sum %= 10;
            r.insertH(sum);
            j = j -> next;
            if(q != NULL)
                q = q -> next;
        }
        if(carry != 0)
        {
            r.insertH(carry);
        }
        return r;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        bigInt a;
        bigInt b;
        bigInt c;
        char arr1[1000];
        char arr2[1000];
        cin>>arr1>>arr2;
        for(int i = strlen(arr1) - 1; i >= 0; i--) {
            a.insertL(arr1[i]);
        }
        for(int i = strlen(arr2) - 1; i >= 0; i--) {
            b.insertL(arr2[i]);
        }
        /*a.print();
        puts("");
        b.print();
        puts("");*/
        if(a.length() > b.length()) c = a + b;
        else c = b + a;
        c.print();
        puts("");
    }
    return 0;
}