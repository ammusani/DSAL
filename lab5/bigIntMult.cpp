#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class bigInt {
    vector<int> p;
    public:
        //bigInt();
        void insertL(char);
        void insertH(int);
        //int value();
        int length();
        int element(int i);
        bigInt operator +(bigInt);
        bigInt operator *(bigInt);
        bigInt operator *(int);
        void print();
        //struct node **getHead();
};

void bigInt :: insertL(char c) {
    p.push_back((int)c - 48);
}

void bigInt :: insertH(int q) {
    p.push_back(q);
}

int bigInt :: length() {
    return p.size();
}

void bigInt :: print() {
    for(auto i = p.rbegin(); i != p.rend(); i++) printf("%d", *i);
    puts(" ");
}

int bigInt :: element(int i) {
    return p[i];
}

bigInt bigInt:: operator +(bigInt q) {
    int sum = 0;
    int carry = 0;
    bigInt r;
    for(int i = 0; i < q.length(); i++) {
        sum = p[i] + q.element(i) + carry;
        r.insertH(sum % 10);
        carry = sum / 10;
        //printf("carryin = %d ", carry);
    }
    //printf("carryout = %d ", carry);
    for(int i = q.length(); i < p.size(); i++) {
        //printf("carry = %d ", carry);
        sum = p[i] + carry;
        r.insertH(sum % 10);
        carry = sum / 10;
    }
    if(carry) r.insertH(carry);
    return r;
}



int main() {

}