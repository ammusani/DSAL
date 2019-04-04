#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class anagram {
    string s;
    int l[50] = {0};
    int len;

    public:
        anagram(string st, int p) {
            l[0] = p;
            len = 1;
            s = st;
        }
        string strr() {
            return s;
        }
        void insert(int k) {
            l[len] = k;
            len++;
        }
        void print() {
            for(int i = 0; i < len; i++) printf("%d ", l[i]);
            puts("");
        }

};

int main() {
    int n;
    scanf("%d", &n);
    char s[101];
    vector<anagram> v;
    for(int i = 1; i <= n; i++) {
        scanf("%s", s);
        int flag = 1;
        sort(s, s + strlen(s));
        if(v.empty()) {
            anagram p((string)s, i);
            v.push_back(p);
        }
        else {
            for(auto j = v.begin(); j != v.end(); j++) {
                if((string)s == (*j).strr()) {
                    (*j).insert(i);
                    flag = 0;
                    break;
                }
            }
            if(flag) {
                anagram p((string)s, i);
                v.push_back(p);
            }
        }
    }
    for(auto i = v.begin(); i != v.end(); i++) {
        (*i).print();
    }
    return 0;
}