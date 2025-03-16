#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int num_inp() {
        int input;
        scanf("%d", &input);
        return input;
    }

    int* arr_inp() {
        int n;
        scanf("%d", &n);
        int* arr = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        return arr;
    }

    int* sp_inp() {
        int n;
        scanf("%d", &n);
        int* arr = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        return arr;
    }

    int compare(const void* a, const void* b) {
        return (*(int*)a - *(int*)b);
    }

    int main() {
        int* a = sp_inp();
        int n = a[0];
        int* arr = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            arr[i] = a[i + 1];
        }
        free(a);

        qsort(arr, n, sizeof(int), compare);

        bool any_divisible = false;
        for (int i = 0; i < n; i++) {
            if (arr[i] % arr[0] == 0) {
                any_divisible = true;
                break;
            }
        }

        if (any_divisible) {
            printf("%d\n", arr[0]);
        } else {
            printf("-1\n");
        }

        free(arr);
        return 0;
    }
