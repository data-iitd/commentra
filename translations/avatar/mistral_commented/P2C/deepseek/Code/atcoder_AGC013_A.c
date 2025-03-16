#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read an integer from standard input
int read_int() {
    int num;
    scanf("%d", &num);
    return num;
}

// Function to read a list of integers from standard input
void read_list(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to remove consecutive duplicates from a list
void remove_consecutive_duplicates(int *arr, int *size) {
    int k = 0;
    for (int i = 0; i < *size; i++) {
        if (i == 0 || arr[i] != arr[i - 1]) {
            arr[k++] = arr[i];
        }
    }
    *size = k;
}

// Main logic to count sandwiched elements
int count_sandwiched_elements(int *arr, int size) {
    int ans = 0;
    for (int i = 1; i < size - 1; i++) {
        if ((arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) || (arr[i - 1] > arr[i] && arr[i] < arr[i + 1])) {
            ans++;
        }
    }
    return ans + 1;
}

int main() {
    int N = read_int();
    int A[N];
    read_list(A, N);

    remove_consecutive_duplicates(A, &N);

    int result = count_sandwiched_elements(A, N);
    printf("%d\n", result);

    return 0;
}
