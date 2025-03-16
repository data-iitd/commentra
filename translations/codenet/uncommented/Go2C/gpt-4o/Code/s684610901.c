#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define INITIAL_BUF_SIZE 10000
#define MAX_BUF_SIZE 100000000
#define INF 1e8

void flush() {
    fflush(stdout);
}

int64_t readInt() {
    int64_t value;
    scanf("%lld", &value);
    return value;
}

bool isInRange(int64_t A, int64_t B, int64_t C) {
    return C >= A && C <= B;
}

int main() {
    // Set buffer size for input
    char buffer[INITIAL_BUF_SIZE];
    setvbuf(stdout, buffer, _IOFBF, MAX_BUF_SIZE);

    int64_t A = readInt();
    int64_t B = readInt();
    int64_t C = readInt();

    if (isInRange(A, B, C)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    flush();
    return 0;
}

/*==========================================
 *             Library
 *==========================================*/
bool nextPermutation(int64_t *arr, int n) {
    int j = n - 2;
    while (j >= 0 && arr[j] >= arr[j + 1]) {
        j--;
    }
    if (j < 0) {
        return false;
    }
    int l = n - 1;
    while (arr[j] >= arr[l]) {
        l--;
    }
    // Swap
    int64_t temp = arr[j];
    arr[j] = arr[l];
    arr[l] = temp;

    // Reverse
    for (int k = j + 1, m = n - 1; k < m; k++, m--) {
        temp = arr[k];
        arr[k] = arr[m];
        arr[m] = temp;
    }
    return true;
}

int64_t max(int64_t a, int64_t b) {
    return (a > b) ? a : b;
}

int64_t min(int64_t a, int64_t b) {
    return (a < b) ? a : b;
}

int64_t sum(int64_t *arr, int size) {
    int64_t total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

void reverse(int64_t *arr, int size) {
    for (int i = 0; i < size / 2; i++) {
        int64_t temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

// Additional utility functions can be added as needed

// <END-OF-CODE>
