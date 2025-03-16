#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char soz[100001]; // Assuming the input string will not exceed 100000 characters
    scanf("%s", soz);
    
    int len = strlen(soz);
    int *a = (int *)malloc((len + 1) * sizeof(int));
    a[0] = 0;

    for (int i = 1; i < len; i++) {
        a[i] = a[i - 1];
        if (soz[i - 1] == soz[i]) {
            a[i]++;
        }
    }

    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int m, l;
        scanf("%d %d", &m, &l);
        arr[i] = a[l - 1] - a[m - 1];
    }

    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }

    free(a);
    free(arr);
    return 0;
}

// <END-OF-CODE>
