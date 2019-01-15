#include<stdio.h>
class rect {
	int len;
	int bre;
	int are;
	public:
		rect();
		void setLen(int);
		void setBre(int);
		int getLen();
		int getBre();
		int area();
		int pArea();
};

rect :: rect() {
	len = 0;
	bre = 0;
}
void rect :: setLen(int val) {
	len = val;
}
void rect :: setBre(int val) {
	bre = val;
}
int rect :: getLen() {
	printf("Length = %d\n", len);
}
int rect :: getBre() {
	printf("Breadth = %d\n", bre);
}
int rect :: area () {
	are = len * bre;
}
int rect :: pArea() {
	printf("Area = %d\n", are);
}

int main() {
	rect rect1;
	int l;
	//printf("%s", "Enter the lenght:\n");
	scanf("%d", &l);
	rect1.setLen(l);
	scanf("%d", &l);
	rect1.setBre(l);
	
	rect1.area();
	rect1.pArea();
}
