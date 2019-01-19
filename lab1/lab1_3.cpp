#include<stdio.h>
#include<string.h>
//#include<iostream>
using namespace std;

class String {
    char arr[1000];
    int len;
    public:
        void setArray(char a[]);
        int length();
        void append(char addArr[]);
        char at(int i);
        void erase(int i);
        char *getArray();
        int getLen();
};

void String :: setArray(char a[]) {
    int i = 0;
    while(a[i] != '\0') {
        arr[i] = a[i];
        i++;
    }
    arr[i] = '\0';
    len = i;
}

int String :: length() {
    return len;
}

void String :: append(char a[]) {
    int i = 0;
    while(a[i] != '\0') {
        arr[len + i] = a[i];
        i++;
    }
    arr[i + len] = '\0';
    len += i;
}

char String :: at(int i) {
    //printf("%c\n", arr[i]);
    char p = arr[i];
    return p;
}

void String :: erase(int i) {
    for(int j = i + 1; j <= len; j++) {
        arr[j - 1] = arr[j];
    }
}

char *String :: getArray() {
    return arr;
}
int String :: getLen() {
    return len;
}
int main() {
    char arr[1000] = "Hi, It's Ali. What\'s up?";
    String strArr;
    strArr.setArray(arr);
    printf("Intial Array:\n");
    printf("%s\n", strArr.getArray());
    printf("Length = %d\n", strArr.getLen());
    printf("Character at index 6:");
    printf("%c\n", strArr.at(6));
    char charArr[] = "Hi There!!";
    strArr.append(charArr);
    printf("After Appending:\n");
    printf("%s\n", strArr.getArray());
    printf("After erasing at index 17:\n");
    strArr.erase(17);
    printf("%s\n", strArr.getArray());
    return 0;
}
