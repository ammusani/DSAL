#include<iostream>

using namespace std;

int main() {
    int t;
    int n;
    int k;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        scanf("%d", &k);
        int arr[101] = {0};
        string s;
        int len;
        for(int i = 0; i < n; i++) {
            cin >> s;
            len = s.length();
            arr[len]++;
        }
        int flag = 1;
        for(int i = 1; i < 101; i++) {
            if(arr[i] % k != 0) {
                flag = 0;
                break;
            }
        }
        if(flag) printf("%s\n", "Possible");
        else printf("%s\n", "Not possible");
    }
}