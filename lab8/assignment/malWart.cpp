//This program solves the malWart problem on hackerrank. Description in MalWart.pdf

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    while(n) {
        int total = 0;
        int k;
        int t;
        multiset <int> :: iterator ptr;     //multiset iterator
        multiset <int> s;                   //multiset s
        for(int i = 0; i < n; i++) {
            scanf("%d", &k);
            for(int i = 0; i < k; i++) {
                scanf("%d", &t);
                s.insert(t);                //adding each bill into the multiset
            }
            ptr = s.begin();                //pointer to the start of the set
            int min = *ptr;                 //set start has the minimum value
            s.erase(ptr);                   //removing the used value
            ptr = s.end();                  //pointer to end, i.e. element after the last
            ptr--;                          //going to last element
            int max = *ptr;                 //last element is max
            s.erase(ptr);                   //removing the last element
            total += (max - min);           //adding the difference of max and min to total
        }
        printf("%d\n", total);
        scanf("%d", &n);
    }
    return 0;
}
