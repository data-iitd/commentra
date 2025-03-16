#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readInt() {
    int num;
    scanf("%d", &num);
    return num;
}

int* readIntArray(int size) {
    int* array = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    return array;
}

void sortArray(int* array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n = readInt();
    int x = readInt();
    int* A = readIntArray(n);

    sortArray(A, n);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (x >= A[i]) {
            ans++;
            x -= A[i];
        } else {
            break;
        }
    }
    if (ans == n && x > 0) {
        ans--;
    }
    printf("%d\n", ans);

    free(A);
    return 0;
}

