#include <stdio.h>

// solution function takes two integers, n and m, as input.
// It adjusts both n and m by subtracting 2 from each.
// It then checks if the adjusted values are less than 0, and if so, it sets them to 1.
// Finally, it returns the product of the adjusted n and m.
int solution(int n, int m) {
    n = n - 2;
    m = m - 2;
    if (n < 0) {
        n = 1;
    }
    if (m < 0) {
        m = 1;
    }
    return n * m;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d\n", solution(n, m));
    return 0;
}

// <END-OF-CODE>
