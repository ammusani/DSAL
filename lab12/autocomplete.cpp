#include<bits/stdc++.h>

using namespace std;

struct node {
    struct node *z[26];
    int eow;
};

class autoComplete {
    struct node *mainNode;

    void print(string s, struct node *n) {
        if(n == NULL) return;
        if(n -> eow == 1) cout << s << endl;
        for(int i = 0; i < 26; i++) {
            if(n -> z[i] != NULL) {
                char j = i + 'a';
                s.push_back(j);
                print(s, n -> z[i]);
                s.pop_back();
            }
        }
    }

    public:
    autoComplete() {
        mainNode = new struct node;
        for(int i = 0; i < 26; i++) {
            mainNode -> z[i] = NULL;
        }
        mainNode -> eow = 0;
    }
    void insert(char *a, int len) {
        struct node *n = mainNode;
        int l;
        for(int i = 0; i < len; i++) {
            l = a[i] - 'a';
            if(n -> z[l] == NULL) {
                n -> z[l] = new struct node;
                for(int i = 0; i < 26; i++) {
                    n -> z[l] -> z[i] = NULL;
                }
                if(i == len - 1) n -> z[l] -> eow = 1;
                else n = n -> z[l];
            }
            else {
                if(i == len - 1) n -> z[l] -> eow = 1;
                else n = n -> z[l];
            }
        }
    }
    void print(char *a, int len) {
        struct node *n = mainNode;
        int flag = 1;
        for(int i = 0; i < len; i++) {
            if(n -> z[(int)(a[i] - 'a')] == NULL) {
                flag = 0;
                printf("not found\n\n");
                break;
            }
            else {
                n = n -> z[(int)(a[i] - 'a')];
            }
        }
        if(flag) {
            string s = (string)a;
            print(s, n);
            puts("");
        }
    }
};

int main() {
    int n;
    int q;
    scanf("%d%d", &n, &q);
    getchar();
    autoComplete aq;
    char arr[27];
    int len;
    for(int i = 0; i < n; i++) {
        scanf("%s", arr);
        len = strlen(arr);
        aq.insert(arr, len);
    }
    for(int i = 0; i < q; i++) {
        scanf("%s", arr);
        len = strlen(arr);
        aq.print(arr, len);
    }
    return 0;
}