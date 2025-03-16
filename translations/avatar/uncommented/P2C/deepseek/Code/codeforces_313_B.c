#include <stdio.h>
#include <string.h>

#define MAX_LEN 100001

int main() {
    char soz[MAX_LEN];
    int a[MAX_LEN];
    int n, m, l;
    scanf("%s", soz);
    int len = strlen(soz);
    a[0] = 0;
    for (int i = 1; i < len; i++) {
        a[i] = a[i - 1];
        if (soz[i - 1] == soz[i]) {
            a[i]++;
        }
    }
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &m, &l);
        arr[i] = a[l - 1] - a[m - 1];
    }
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}
