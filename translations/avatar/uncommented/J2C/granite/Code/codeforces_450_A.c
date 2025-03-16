
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int *arr = (int*)malloc(n * sizeof(int));
    int *ans = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        ans[i] = i + 1;
    }
    int i = 0, j = 0;
    while (i < n) {
        if (arr[i] <= m) {
            i++;
        } else {
            int temp = arr[i] - m;
            arr[i] = temp;
            ans[i] = ans[j];
            j++;
        }
    }
    printf("%d", ans[i - 1]);
    return 0;
}
//END-OF-CODE