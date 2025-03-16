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
    char s[100000];
    for (int i = 0; i < n; i++) {
        if ((sum - arr[i]) % (n - 1) == 0 && (sum - arr[i]) / (n - 1) == arr[i]) {
            c++;
            sprintf(s, "%d ", i + 1);
            strcat(s, s);
        }
    }
    printf("%d\n", c);
    printf("%s", s);
    return 0;
}

