
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int num;
} Val;

typedef struct {
    Val* arr;
    int len;
} ByNum;

int max(int a, int b, int c) {
    int m = a;
    if (m < b) {
        m = b;
    }
    if (m < c) {
        m = c;
    }
    return m;
}

void swap(Val* a, Val* b) {
    Val temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Val* arr, int low, int high) {
    int pivot = arr[high].num;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].num < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(Val* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int A, B, C, K;
    scanf("%d %d %d %d", &A, &B, &C, &K);

    Val arr[3];
    arr[0].id = 1;
    arr[0].num = A;
    arr[1].id = 2;
    arr[1].num = B;
    arr[2].id = 3;
    arr[2].num = C;

    ByNum bn;
    bn.arr = arr;
    bn.len = 3;

    quickSort(bn.arr, 0, bn.len - 1);

    int maxVal = max(arr[0].num, arr[1].num, arr[2].num);
    for (int i = 0; i < K; i++) {
        maxVal *= 2;
    }

    int rest = arr[0].num + arr[1].num;
    if (arr[2].num!= maxVal) {
        rest += arr[2].num;
    }

    printf("%d\n", maxVal + rest);

    return 0;
}
