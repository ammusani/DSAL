#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    int n;
    scanf("%d", &t);
    string s;
    int i;
    int j;
    int k;
    int len;
    int count;
    string s1;
    string s2;
    while(t--) {
        scanf("%d",  &n);
        unordered_map<int, string> u;
        for(i = 0; i < n + 2; i++) {
            cin >> s;
            u[i] = s;
        }
        len = s.length();
        vector<vector<int>> aList;
        vector<int> aa;
        for(i = 0; i < n + 2; i++) aList.push_back(aa);
        for(i = 0; i < n + 1; i++) {
            for(j = i + 1; j < n + 2; j++) {
                count = 0;
                for(k = 0; k < len; k++) {
                    if(u[i].at(k) == u[j].at(k)) count++;
                }
                if(count == len - 1) {
                   aList[i].push_back(j);
                   aList[j].push_back(i);
                }
            }
        }
        int minBFS(vector<vector<int>>, int);
        int min = minBFS(aList, n);
        printf("%d\n", min);
    }
    return 0;
}
int minBFS(vector<vector<int>> t, int n) {
    int visit[n + 2];
    int dis[n + 2];
    for(int i = 0; i < n + 2; i++) {
        visit[i] = 0;
        dis[i] = 0;
    }
    int curr;
    queue<int> q;
    q.push(n);
    dis[n] = 0;
    visit[n] = 1;
    while(!q.empty()) {
        curr = q.front();
        q.pop();
        for(auto i = t[curr].begin(); i != t[curr].end(); i++) {
            if(visit[*i] == 0) {
                dis[*i] = dis[curr] + 1;
                q.push(*i);
                visit[*i] = 1;
            }
            if(*i == n + 1) return dis[n + 1];
        }
    }
    return dis[n + 1];
}