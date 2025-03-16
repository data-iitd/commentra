#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_int() {
    int v;
    scanf("%d", &v);
    return v;
}

int* read_ints(int n) {
    int* ret = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        ret[i] = read_int();
    }
    return ret;
}

void sort_asc(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void sort_desc(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int N = read_int();
    int K = read_int();
    
    int* As = read_ints(N);
    int* Fs = read_ints(N);
    
    sort_asc(As, N);
    sort_desc(Fs, N);
    
    int* scores = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scores[i] = As[i] * Fs[i];
    }
    
    sort_desc(scores, N);
    
    int ok = scores[0];
    int ng = -1;
    
    while (ok - ng > 1) {
        int mid = (ok + ng) / 2;
        
        int isOK = 1;
        int k = K;
        for (int i = 0; isOK && i < N; i++) {
            if (As[i] * Fs[i] > mid) {
                k -= As[i] - mid / Fs[i];
            }
            if (k < 0) {
                isOK = 0;
            }
        }
        
        if (isOK) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    
    printf("%d\n", ok);
    
    free(As);
    free(Fs);
    free(scores);
    
    return 0;
}
