#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class matrix {
    int m;
    int n;
    int mat[100][100];
    public:
        matrix(int i, int j) {
            m = i;
            n = j;
            //mat = (int**)malloc(m*n*sizeof(int));
        }
        matrix operator *(int);
        void addValue(int, int, int);
        void printMat();
};

matrix matrix :: operator *(int p) {
    matrix temp(m, n);
    for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) temp.mat[i][j] = mat[i][j] * p;
    return temp;
}

void matrix :: addValue(int i, int j, int k) {
    mat[i][j] = k;
}

void matrix :: printMat() {
    for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) printf("%d ", mat[i][j]);
}

int main() {
    int t;
    int m;
    int n;
    int p;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &m, &n, &p);
        matrix a(m, n);
        int k;
        //a.initialize(m, n);
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) {
            scanf("%d", &k);
            a.addValue(i, j, k);
        }    
        //matrix b;
        //scanf("%d%d", &m, &n);
        /*matrix b(m, n);
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) {
            scanf("%d", &k);
            b.addValue(i, j, k);
        }*/
        a = a * p;
        a.printMat();
        puts("");
    }
    return 0;
}    
