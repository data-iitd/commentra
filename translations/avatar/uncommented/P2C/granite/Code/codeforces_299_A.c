
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % min!= 0) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        printf("%d %d", min, -1);
    } else {
        printf("%d %d", min, 0);
    }
    free(arr);
    return 0;
}
// END-OF-CODE