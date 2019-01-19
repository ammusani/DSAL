#include<stdio.h>
#include<string.h>

class bigInt {
    char numArr[1000];
    int len;

    public:
        void setLen(int i);
        int getLen();
        void setNum(char arr[]);
        void addInt(char arr[], int len2);
        char *getNum();
        void printNum();
};

void bigInt :: setLen(int i) {
    len = i;
}

int bigInt :: getLen() {
    return len;
}

void bigInt :: setNum(char arr[]) {
    numArr[len] = '\0';
    for(int i = len - 1, j = 0; i >= 0; i--, j++) {
        numArr[i] = arr[j];
    }
}

void bigInt :: addInt(char arr[], int len2) {
    int i;
    for(i = 0; i < len2; i++) {
        numArr[i] += (arr[i] - 96);
        if(numArr[i + 1] != '\0') numArr[i + 1] += numArr[i] / 10;
        else {
            numArr[i + 1] = (numArr[i] / 10) + 48;
            numArr[i + 2] = '\0';
            len++;
        }
        numArr[i] %= 10;
        numArr[i] += 48;
    }
    for(; i < len; i++) {
        numArr[i] -= 48;
        if(numArr[i + 1] != '\0') numArr[i + 1] += numArr[i] / 10;
        else {
            numArr[i + 1] = (numArr[i] / 10) + 48;
            numArr[i + 2] = '\0';
            len++;
        }
        //numArr[i + 1] += numArr[i] / 10;
        numArr[i] %= 10;
        numArr[i] += 48;
    }
}

char *bigInt :: getNum() {
    return numArr;
}

void bigInt :: printNum() {
    int flag = 0;
    for(int i = len - 1; i >= 0; i--) {
        if(numArr[i] > 48) flag = 1;
        if(flag) printf("%c", numArr[i]);
    }
    puts("");
}

int main() {
        /*void setLen(int i);
        int getLen();
        void setNum(char arr[]);
        void addInt(char arr[], int len2);
        char *getNum();
        void printNum();*/
    char num1[] = "87544565648";
    char num2[] = "214787948486";
    bigInt arr1;
    bigInt arr2;
    arr1.setLen(strlen(num1));
    arr2.setLen(strlen(num2));
    arr1.setNum(num1);
    arr2.setNum(num2);
    if(arr1.getLen() >= arr2.getLen()) {
        arr1.addInt(arr2.getNum(), arr2.getLen());
        arr1.printNum();
    }
    else {
        arr2.addInt(arr1.getNum(), arr1.getLen());
        arr2.printNum();
    }
}