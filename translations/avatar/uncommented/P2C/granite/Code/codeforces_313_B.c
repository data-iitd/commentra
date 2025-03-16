
#include <stdio.h>
#include <string.h>

int main() {
    char soz[100001];
    scanf("%s", soz);
    int a[100001] = {0};
    for (int i = 1; i < strlen(soz); i++) {
        a[i] = a[i - 1];
        if (soz[i - 1] == soz[i]) {
            a[i] += 1;
        }
    }
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        int m, l;
        scanf("%d %d", &m, &l);
        arr[i] = a[l - 1] - a[m - 1];
    }
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}
