#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    int sum = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    int c = 0;
    char str[100];

    for (int i = 0; i < n; i++) {
        if ((sum - arr[i]) % (n - 1) == 0 && (sum - arr[i]) / (n - 1) == arr[i]) {
            c++;
            sprintf(str, "%d ", i + 1);
            printf("%s", str);
        }
    }

    printf("\n%d", c);
    printf("\n%s", str);

    return 0;
}

