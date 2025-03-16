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
    char sb[1000] = "";

    for (int i = 0; i < n; i++) {
        if ((sum - arr[i]) % (n - 1) == 0 && (sum - arr[i]) / (n - 1) == arr[i]) {
            c++;
            char temp[20];
            sprintf(temp, "%d ", i + 1);
            strcat(sb, temp);
        }
    }

    printf("%d\n", c);
    printf("%s", sb);

    return 0;
}
