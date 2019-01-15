#include<iostream>
#include<bits/stdc++.h>
#include<stack>
using namespace std;

int main() {
	string post;
	getline(cin, post);
	long long int evaPost(string str);
	long long int k = evaPost(post);
	printf("%lld\n", k);
}

long long int evaPost(string str) {
	int i = 1;
	stack <long long int> s1;
	s1.push(str[0] - 48);
	while(str[i] != '\0') {
		if(str[i] >= 48 && str[i] <= 57) {
			if(str[i - 1] == ' ') s1.push(str[i] - 48);
			else {
				long long int k = s1.top();
				k *= 10;
				k += (str[i] - 48);
				s1.pop();
				s1.push(k);
			}
		}
		else if(str[i] != ' ') {
			long long int k1 = s1.top();
			s1.pop();
			long long int k2 = s1.top();
			s1.pop();
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
			s1.push(k3);
		}
		i++;
	}
	return s1.top();
}
