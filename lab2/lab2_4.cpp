#include<iostream>
#include<stack>
#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    while(n--) {
        string infix;
        getline(cin, infix);
        stack<char> s1;
        int i = 0;
        int num = 1;
        while(infix[i] != '\0') {
            if(infix[i] >= 48 && infix[i] <= 57) {
                printf("%c", infix[i]);
                num = 1;
            }
            else if(infix[i] == ' ' && num == 1) {
                printf(" ");
                num = 0;
            } 
            else {
                //num = 1;
                //printf("");
                if(s1.empty()) s1.push(infix[i]);
                else {
                    switch(infix[i]) {
                        case '*': {
                            while(!s1.empty() && (s1.top() == '*' || s1.top() == '/' || s1.top() == '^')) {
                                printf("%c ", s1.top());
                                s1.pop();
                            }
                            s1.push('*');
                            break;
                        }
                        case '/': {
                            while(!s1.empty() && (s1.top() == '*' || s1.top() == '/' || s1.top() == '^')) {
                                printf("%c ", s1.top());
                                s1.pop();
                            }
                            s1.push('/');
                            break;
                        }
                        case '+': {
                            while(!s1.empty() && (s1.top() == '+' || s1.top() == '-' || s1.top() == '*' || s1.top() == '/' || s1.top() == '^')) {
                                printf("%c ", s1.top());
                                s1.pop();
                            }
                            s1.push('+');
                            break;
                        }
                        case '-': {
                            while(!s1.empty() && (s1.top() == '+' || s1.top() == '-' || s1.top() == '*' || s1.top() == '/' || s1.top() == '^')) {
                                printf("%c ", s1.top());
                                s1.pop();
                            }
                            s1.push('-');
                            break;
                        }
                        case '^': {
                            s1.push('^');
                            break;
                        }
                        default: break;
                    }
                }
            }
            i++;
        }
        printf(" ");
        while(!s1.empty()) {
            printf("%c ", s1.top());
            s1.pop();
        }
        puts(" ");
    }
    return 0;
}