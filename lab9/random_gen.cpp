#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

using namespace std;

int main() {

	srand(time(0));
	
	FILE *rnd;

	rnd = fopen("random.txt", "w");
	for(int i = 0; i < 1000000; i++) {
		fprintf(rnd, "%d\n", rand());
	}

	fclose(rnd);
	return 0;
}