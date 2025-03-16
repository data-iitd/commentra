#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    int l[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }

    int ans = n - 1;
    int last = 0;

    for (int i = 0; i < n; i++) {
        ans += abs(last - l[i]) + 1;
        last = l[i];
    }

    printf("The value of the answer is: %d\n", ans);

    return 0;
}
