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
    char buffer[1000];
    int bufferIndex = 0;
    for (int i = 0; i < n; i++) {
        if ((sum - arr[i]) % (n - 1) == 0 && (sum - arr[i]) / (n - 1) == arr[i]) {
            c++;
            bufferIndex += sprintf(buffer + bufferIndex, "%d ", i + 1);
        }
    }
    printf("%d\n", c);
    printf("%s\n", buffer);
    return 0;
}
