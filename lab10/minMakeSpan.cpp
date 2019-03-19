#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool comp(tuple<int, int> a, tuple<int, int> b) {
    if(get<1> (a) > get<1> (b)) {
        return true;
    }
    return false;
}

int min(int *a, int m) {
    int min_index = 1;
    int min_value = a[1];
    for(int i = 1; i <= m; i++) {
        if(a[i] == 0) return i;
        else if (a[i] < min_value) {
            min_value = a[i];
            min_index = i;
        }
    }
    return min_index;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        int m;
        scanf("%d%d", &n, &m);
        vector<tuple<int, int>> v;
        for(int i = 1; i <= n; i++) {
            int value;
            scanf("%d", &value);
            v.push_back(make_tuple(i, value));
        }
        sort(v.begin(), v.end(), comp);
        /*for(auto z = v.begin(); z < v.end(); z++) {
            printf("%d ", get<1>(*z));
        }*/
        int a[m + 1];
        for(int i = 0; i <= m; i++) a[i] = 0;
        for(auto z = v.begin(); z < v.end(); z++) {
            int mach = min(a, m);
            int low = a[mach];
            int job = get<0>(*z);
            a[mach] += get<1>(*z);
            printf("Job %d in machine %d from %d to %d\n", job, mach, low, a[mach]);
        }
        puts("");
    }
    return 0;
}

