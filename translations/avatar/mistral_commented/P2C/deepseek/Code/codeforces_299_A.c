#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int read_num() {
    int num;
    scanf("%d", &num);
    return num;
}

int* read_arr() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

int* read_sp_arr() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

int main() {
    // Read input from file instead of user input
    int a[1000];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Sort the array
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    // Find the largest number that leaves a remainder when divided by any number in the list
    int largest = a[0];
    bool valid = true;
    for (int i = 1; i < n; i++) {
        if (largest % a[i] == 0) {
            valid = false;
            break;
        }
    }

    if (valid) {
        printf("%d\n", largest);
    } else {
        printf("-1\n");
    }

    return 0;
}
