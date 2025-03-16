#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nextInt() {
    int n;
    scanf("%d", &n);
    return n;
}

void sortArray(int *ar, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (ar[j] > ar[j + 1]) {
                int temp = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n = nextInt();
    int size = 3 * n;
    int ar[size];
    for (int i = 0; i < size; i++) {
        ar[i] = nextInt();
    }
    sortArray(ar, size);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ar[size - (i + 1) * 2];
    }
    printf("%d\n", sum);
    return 0;
}
