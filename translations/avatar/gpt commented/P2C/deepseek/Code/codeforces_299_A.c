#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_inp() {
        int num;
        scanf("%d", &num);
        return num;
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

    int main() {
        int* a = sp_inp();
        int n = a[0];
        int* arr = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            arr[i] = a[i + 1];
        }
        free(a);

        qsort(arr, n, sizeof(int), (int (*)(const void*, const void*))compare);

        if (n == 0 || arr[0] == 0) {
            printf("-1\n");
            free(arr);
            return 0;
        }

        int all_divisible = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] % arr[0] != 0) {
                all_divisible = 0;
                break;
            }
        }

        if (all_divisible) {
            printf("%d\n", arr[0]);
        } else {
            printf("-1\n");
        }

        free(arr);
        return 0;
    }

    int compare(const void* a, const void* b) {
        return (*(int*)a - *(int*)b);
    }
