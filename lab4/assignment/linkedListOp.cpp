#include<iostream>
#include<string.h>
using namespace std;

struct node {
    int data;
    struct node* next;
};

class List {
    struct node *head;
    struct node *last;
    int len;
    public:
        List();
        void append(int);
        void insertAt(int, int);
        //int value();
        int length();
        //List operator +(List);
        void display();
        //struct node **getHead();
        void updateAt(int, int);
        void deleteAt(int);
        void reverse();
};

List :: List() {
    head = new node;
    last = head;
    head -> next = NULL;
    len = 0;
}

void List :: append(int p) {
    struct node *q;
    q = new node;
    q -> next = NULL;
    q -> data = p;
    last -> next = q;
    last = q;
    len++;
}

void List :: insertAt(int i, int v) {
    struct node *r = new node;
    struct node *p = head;
    for(int j = 1; j < i; j++) p = p -> next;
    r -> data = v;
    r -> next = p -> next;
    p -> next = r;
    if(i==len+1)
        last=last->next;
    len++;
}

int List :: length() {
    return len;
}

void List :: deleteAt(int i) {
    struct node *r;
    struct node *p = head;
    for(int j = 1; j < i; j++) p = p -> next;
    r = p -> next;
    p -> next = r -> next;
    if(i == len) last = p;
    delete r;
    len--;
}

void List :: updateAt(int i, int p) {
    struct node *q;
    q = head; 
    for(int j = 0; j < i; j++) q = q -> next;
    q -> data = p;
}
void List :: display() {
    struct node *p;
    p = head -> next;
    while(p -> next != NULL) {
        printf("%d ", p -> data);
        p = p -> next;
    }
    printf("%d\n", p -> data);
}

void List :: reverse() {
    struct node *p;
    struct node *q;
    struct node *r;
    if(len == 0 || len == 1) return;
    else {
        p = head -> next;
        q = p -> next;
        r = q -> next;
        while(r != NULL) {
            q -> next = p;
            if(p == head -> next ) p -> next == NULL;
            p = q;
            q = r;
            r = r -> next;
        }
        q -> next = p;
        last = head -> next;
        head -> next = q;
        last -> next = NULL;
    }
}

int main() {
    int p = 1;
    List z;
    while(p != 7) {
        scanf("%d", &p);
        switch(p) {
            case 1: {
                int value;
                scanf("%d", &value);
                z.append(value);
                break;
            }
            case 2: {
                int i;
                int value;
                scanf("%d%d", &i, &value);
                z.insertAt(i, value);
                break;
            }
            case 3: {
                int i;
                scanf("%d", &i);
                z.deleteAt(i);
                break;
            }
            case 4: {
                int i;
                int value;
                scanf("%d%d", &i, &value);
                z.updateAt(i, value);
                break;
            }
            case 5: {
                z.reverse();
                break;
            }
            case 6: {
                z.display();
                break;
            }
            case 7: {
                break;
            }
        }
        //scanf("%d", &p);
    }
    return 0;
}