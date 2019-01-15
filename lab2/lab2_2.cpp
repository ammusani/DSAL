#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class stacks {
	long long int value[1000];
	int len;
	public:
		void in(long long int); //push function alias
		void out();		//pop function alias
		long long int up();    // top function alias
		void inValue();		// to initialize all values of array and length
};

void stacks :: in (long long int n) {
	value[len] = n;
	len++;
}

void stacks :: out() {
	len--;
	value[len] = 0;
}

long long int stacks :: up() {
	return value[len - 1];
}

void stacks :: inValue() {
	for(int i = 0; i < 1000; i++) value[i] = 0;
	len = 0;
}

int main() {
	string post;
	getline(cin, post);
	long long int evaPost(string str);
	long long int k = evaPost(post);
	printf("%lld\n", k);
}

long long int evaPost(string str) {
	int i = 1;
	stacks s1;
	s1.inValue();
	s1.in(str[0] - 48);
	while(str[i] != '\0') {
		if(str[i] >= 48 && str[i] <= 57) {
			if(str[i - 1] == ' ') s1.in(str[i] - 48);
			else {
				long long int k = s1.up();
				k *= 10;
				k += (str[i] - 48);
				s1.out();
				s1.in(k);
			}
		}
		else if(str[i] != ' ') {
			long long int k1 = s1.up();
			s1.out();
			long long int k2 = s1.up();
			s1.out();
			long long int k3;
			switch(str[i]) {
				case '+': {
					k3 = k2 + k1;
					break;
				}
				case '-': {
					k3 = k2 - k1;
					break;
				}
				case '*': {
					k3 = k2 * k1;
					break;
				}
				case '/': {
					k3 = k2 / k1;
					break;
				}
				case '^': {
					k3 = pow(k2, k1);
					break;
				}
				default: break;
			}
			s1.in(k3);
		}
		i++;
	}
	return s1.up();
}
