#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, y;
    int xt = -1, yt = -1;
    int a[3][7] = {
        {1, 3, 5, 7, 8, 10, 12},
        {4, 6, 9, 11},
        {2}
    };
    int sizes[3] = {7, 4, 1}; // Sizes of each sub-array

    // Read integers x and y
    scanf("%d %d", &x, &y);

    // Check which group x belongs to
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            if (x == a[i][j]) {
                xt = i;
            }
            if (y == a[i][j]) {
                yt = i;
            }
        }
    }

    // Compare groups and print result
    if (xt == yt) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

// <END-OF-CODE>
