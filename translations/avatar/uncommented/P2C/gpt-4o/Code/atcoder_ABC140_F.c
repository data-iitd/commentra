#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int I() {
    int x;
    scanf("%d", &x);
    return x;
}

int* LI(int n) {
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

int compare(const void* a, const void* b) {
    return (*(int*)b - *(int*)a); // Sort in descending order
}

const char* main() {
    int N = I();
    int* S = LI(N);
    qsort(S, N, sizeof(int), compare);

    bool* flag = (bool*)malloc(N * sizeof(bool));
    for (int i = 0; i < N; i++) {
        flag[i] = true;
    }

    int* cur = (int*)malloc(N * sizeof(int));
    int cur_size = 0;
    cur[cur_size++] = S[0];
    flag[0] = false;

    for (int i = 0; i < N; i++) {
        int j = 0;
        int jM = cur_size;

        for (int k = 0; k < N; k++) {
            if (flag[k] && S[k] < cur[j]) {
                cur[cur_size++] = S[k];
                j++;
                flag[k] = false;
                if (j == jM) {
                    break;
                }
            }
        }

        if (j < jM) {
            free(S);
            free(flag);
            free(cur);
            return "No";
        }

        // Sort cur in descending order
        qsort(cur, cur_size, sizeof(int), compare);
    }

    free(S);
    free(flag);
    free(cur);
    return "Yes";
}

int main() {
    printf("%s\n", main());
    return 0;
}

// <END-OF-CODE>
