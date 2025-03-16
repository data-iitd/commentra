#include <stdio.h>

int main() {
    int n, a = 0, b = 0, c = 0;
    scanf("%d", &n);

    // Sum all n elements
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        a += num;
    }

    // Sum n-1 elements
    for (int i = 0; i < n - 1; i++) {
        int num;
        scanf("%d", &num);
        b += num;
    }

    // Sum n-2 elements
    for (int i = 0; i < n - 2; i++) {
        int num;
        scanf("%d", &num);
        c += num;
    }

    // Calculate the differences
    int x = a - b;
    int y = b - c;

    // Output the results
    printf("%d\n%d\n", x, y);

    return 0;
}
