#include<stdio.h>

class Mat {
	int n;
	int arr[100][100];
	
	public:
		void setN(int);
		void setMat(int i, int j, int val);
		int getN();
		int getElement(int i, int j);
		void isSymmetric();
};

void Mat :: setN(int val) {
	n =  val;
}
void Mat :: setMat(int i, int j, int val) {
	arr[i][j] = val;
}
int Mat :: getN() {
	return n;
}
int Mat :: getElement(int i, int j) {
	return arr[i][j];
}
void Mat :: isSymmetric() {
	int flag = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(arr[i][j] != arr[j][i]) {
				flag = 0;
				break;
			}
		}
		if(flag == 0) break;
	}
	if(flag) printf("%s", "Symmetric\n");
	else printf("%s", "Asymmetric\n");
}

int main() {
	int p;
	scanf("%d", &p);
	Mat a;
	a.setN(p);
	int k;
	for(int i = 1; i <= p; i++) {
		for(int j = 1; j <= p; j++) {
			scanf("%d", &k);
			a.setMat(i, j, k);
		}
	}
	a.isSymmetric();
}
