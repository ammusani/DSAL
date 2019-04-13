#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int q;
    unordered_set<string> u;
    scanf("%d%d", &n, &q);
    string str;
    for(int i = 0; i < n; i++) {
        cin >> str;
        u.insert(str);
    }
    string z;
    string ns;
    for(int kkk = 0; kkk < q; kkk++) {
        set<string> s;
        cin >> z;
        ns = z;
        for(auto i = z.begin(); i != z.end(); i++) {
            z.erase(i);
            if(u.find(z) != u.end()) s.insert(z);
            z = ns;
            switch(*i) {
                case 'a': {
                    *i = 'e';
                    if(u.find(z) != u.end()) s.insert(z);
                    *i = 'i';
                    if(u.find(z) != u.end()) s.insert(z);
                    *i = 'o';
                    if(u.find(z) != u.end()) s.insert(z);
                    *i = 'u';
                    if(u.find(z) != u.end()) s.insert(z);
                    *i = 'a';
                    break;
                }
                case 'e': {
                    *i = 'a';
                    if(u.find(z) != u.end()) s.insert(z);
                    *i = 'i';
                    if(u.find(z) != u.end()) s.insert(z);
                    *i = 'o';
                    if(u.find(z) != u.end()) s.insert(z);
                    *i = 'u';
                    if(u.find(z) != u.end()) s.insert(z);
                    *i = 'e';
                    break;
                }
                case 'i': {
                    *i = 'e';
                    if(u.find(z) != u.end()) s.insert(z);
                    *i = 'a';
                    if(u.find(z) != u.end()) s.insert(z);
                    *i = 'o';
                    if(u.find(z) != u.end()) s.insert(z);
                    *i = 'u';
                    if(u.find(z) != u.end()) s.insert(z);
                    *i = 'i';
                    break;
                }
                case 'o': {
                    *i = 'e';
                    if(u.find(z) != u.end()) s.insert(z);
                    *i = 'i';
                    if(u.find(z) != u.end()) s.insert(z);
                    *i = 'a';
                    if(u.find(z) != u.end()) s.insert(z);
                    *i = 'u';
                    if(u.find(z) != u.end()) s.insert(z);
                    *i = 'o';
                    break;
                }
                case 'u': {
                    *i = 'e';
                    if(u.find(z) != u.end()) s.insert(z);
                    *i = 'i';
                    if(u.find(z) != u.end()) s.insert(z);
                    *i = 'o';
                    if(u.find(z) != u.end()) s.insert(z);
                    *i = 'a';
                    if(u.find(z) != u.end()) s.insert(z);
                    *i = 'u';
                    break;
                }
                default: {
                    break;
                }
            }
            auto jj = z.end() - 1;
            if(i != jj) {
                char temp = *i;
                *i = *(i + 1);
                *(i + 1) = temp;
                if(u.find(z) != u.end()) s.insert(z);
                z = ns;
            }
        }
        for(auto i = s.begin(); i != s.end(); i++) {
            cout << *i <<endl;
        }
        puts("");
    }
    return 0;
}