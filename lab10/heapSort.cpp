#include<iostream>
using namespace std;

class heap {
    int n;
    int *arr;
    int counter = 0;
    public:
    heap(int);
    void insertEl(int);
    void heapifyUp();
    void deleteEl();
    int topEl();
    void heapifyDown(int);
};

heap :: heap(int k) {
    n = k;
    arr = (int*)malloc((n + 1) * sizeof(int));
}

void heap :: insertEl(int el) {
    counter++;
    arr[counter] = el;
    heapifyUp();
    //for(int i = 1; i <= counter; i++) printf("%d ", arr[i]);
    //puts("");
}

void heap :: heapifyUp() {
    int i = counter;
    while(i > 1) {
        if(arr[i / 2] > arr[i]) {
            int k = arr[i / 2];
            arr[i / 2] = arr[i];
            arr[i] = k;
            i /= 2;
        }
        else break;
    }
}

void heap :: deleteEl() {
    arr[1] = arr[counter];
    counter--;
    heapifyDown(1);
    //for(int i = 1; i <= counter; i++) printf("%d ", arr[i]);
    //puts("");
}

void heap :: heapifyDown(int i) {
    if (i > counter) return;
    int flag = 1;
    if( 2 * i + 1 <= counter) {
        if(arr[2 * i + 1] < arr[2 * i]) {
            if(arr[2 * i + 1] < arr[i]){
                int k = arr[2 * i + 1];
                arr[2 * i + 1] = arr[i];
                arr[i] = k;
                heapifyDown(2 * i + 1);
            }
            else return;
        }
        else {
            if(arr[2 * i] < arr[i]) {
                int k = arr[2 * i];
                arr[2 * i] = arr[i];
                arr[i] = k;
                heapifyDown(2 * i);
            }
            else return;
        }
    }
    else if (2 * i <= counter){
        if(arr[2 * i] < arr[i]) {
            int k = arr[2 * i];
            arr[2 * i] = arr[i];
            arr[i] = k;
            heapifyDown(2 * i);
        }
    }
}

int heap :: topEl() {
    return arr[1];
}


int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        heap h(n);
        int kk;
        for(int k = 0; k < n; k++) {
            scanf("%d", &kk);
            h.insertEl(kk);
        }
        int solution[n];
        for (int k = 0; k < n; k++) {
            solution[k] = h.topEl();
            h.deleteEl();
        }
        for(int i = 0; i < n; i++) {
            printf("%d ", solution[i]);
        }
        puts("");
    }
    return 0;
}
