#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
    int q;
    scanf("%d", &q);
    priority_queue<int, vector<int>, greater<int>> pMin;
    priority_queue<int> pMax;
    int k;
    int x;
    while(q--) {
        scanf("%d", &k);
        switch(k) {
            case 1: {
                scanf("%d", &x);
                pMin.push(x);
                pMax.push(x);
                break;
            }
            case 2: {
                int flag = 0;
                scanf("%d", &x);
                priority_queue<int> pMax2;
                priority_queue<int, vector<int>, greater<int>> pMin2;
                while(!pMax.empty()) {
                    if(pMax.top() == x) {
                        flag = 1;
                        pMax.pop();
                        break;
                    }
                    else {
                        pMax2.push(pMax.top());
                        pMax.pop();
                    }
                }
                if(flag == 0) {
                    pMax = pMax2;
                    printf("%d\n", -1);
                }
                else {
                    while(!pMax2.empty()) {
                        pMax.push(pMax2.top());
                        pMax2.pop();
                    }
                    while(!pMin.empty()) {
                        if(pMin.top() == x) {
                            pMin.pop();
                            break;
                        }
                        else {
                            pMin2.push(pMin.top());
                            pMin.pop();
                        }
                    }
                    while(!pMin2.empty()) {
                        pMin.push(pMin2.top());
                        pMin2.pop();
                    }
                }
                break;
            }
            case 3: {
                if(!pMax.empty()) printf("%d\n", pMax.top());
                else printf("%d\n", -1);
                break;
            }
            case 4: {
                if(!pMin.empty()) printf("%d\n", pMin.top());
                else printf("%d\n", -1);
                break;
            }
        }
    }
}