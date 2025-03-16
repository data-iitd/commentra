#include <stdio.h>
#include <stdlib.h>

int readInt() {
    int num;
    scanf("%d", &num);
    return num;
}

int* readIntArray() {
    int* arr = (int*)malloc(sizeof(int) * 1000); // Assuming the maximum size of the array
    char ch;
    int i = 0;
    while (scanf("%d%c", &arr[i], &ch) == 2) {
        i++;
        if (ch == '\n') break;
    }
    return arr;
}

int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int N = readInt();
    int* S = readIntArray();
    qsort(S, N, sizeof(int), compare);
    int flag[1000] = {0};
    int cur[1000];
    cur[0] = S[0];
    flag[0] = 1;
    for (int i = 0; i < N; i++) {
        int j = 0;
        int jM = 0;
        for (int k = 0; k < N; k++) {
            if (!flag[k] && S[k] < cur[j]) {
                cur[++j] = S[k];
                flag[k] = 1;
                jM++;
                if (j == jM) break;
            }
        }
        if (j == jM) {
            qsort(cur, j + 1, sizeof(int), compare);
        } else {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}
