#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    char res[10000]; // Assuming the result won't exceed 10000 characters
    int o = 0, e = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            o++;
        } else {
            e++;
        }
    }

    int index = 0;
    for (int i = 0; i < k; i++) {
        int l, r;
        scanf("%d %d", &l, &r);

        if ((r - l + 1) % 2 == 1) {
            res[index++] = '0';
            res[index++] = '\n';
        } else {
            if ((r - l + 1) / 2 <= o && (r - l + 1) / 2 <= e) {
                res[index++] = '1';
                res[index++] = '\n';
            } else {
                res[index++] = '0';
                res[index++] = '\n';
            }
        }
    }

    res[index] = '\0'; // Null-terminate the result string
    printf("%s", res);

    return 0;
}
