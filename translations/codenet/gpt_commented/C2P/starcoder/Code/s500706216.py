#include <stdio.h>

#define MAX_N 200000
#define MAX_K 200000

int main() {
    int n, k;
    scanf("%d%d", &n, &k);

    int a[MAX_N], tmpa[MAX_N], light[MAX_N + 10] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        int r, l;
        r = i - a[i];
        l = i + a[i];
        light[(r < 0? 0 : r)]++;
        light[(l + 1 > n? n + 1 : l + 1)]--;
    }

    for (int i = 0; i < k; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            tmpa[j] = a[j];
            sum += light[j];
            a[j] = sum;
        }

        for (int j = 0; j < n; j++) {
            int r = j - tmpa[j];
            int l = j + tmpa[j];
            light[(r < 0? 0 : r)]--;
            light[(l + 1 > n? n + 1 : l + 1)]++;

            r = j - a[j];
            l = j + a[j];
            light[(r < 0? 0 : r)]++;
            light[(l + 1 > n? n + 1 : l + 1)]--;
        }

        bool isSame = True;
        for (int j = 0; j < n - 1; j++) {
            if (a[j]!= a[j + 1]) {
                isSame = False;
                break;
            }
        }
        if (isSame && a[0] == n) {
            break;
        }
    }

    for (int j = 0; j < n; j++) {
        printf("%d", a[j]);
        printf(j == n - 1? "\n" : " ");
    }
    return 0;
}
