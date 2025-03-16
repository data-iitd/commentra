#include <stdio.h>

int main() {
    int c[3][3];
    int a[3] = {0}, b[3] = {0};

    // Read the 3x3 matrix
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    b[0] = c[0][0] - a[0];
    b[1] = c[0][1] - a[0];
    b[2] = c[0][2] - a[0];
    a[1] = c[1][0] - c[0][0];
    a[2] = c[2][0] - c[0][0];

    if (a[1] == c[1][1] - c[0][1] && a[1] == c[1][2] - c[0][2] &&
        a[2] == c[2][1] - c[0][1] && a[2] == c[2][2] - c[0][2]) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

// <END-OF-CODE>
