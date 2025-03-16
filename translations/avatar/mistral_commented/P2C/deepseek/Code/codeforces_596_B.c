#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    int r[n];
    printf("Enter the elements of the list separated by spaces: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &r[i]);
    }

    int ans = abs(r[0]);

    for (int i = 1; i < n; i++) {
        ans += abs(r[i] - r[i-1]);
    }

    printf("The final answer is: %d\n", ans);

    return 0;
}
