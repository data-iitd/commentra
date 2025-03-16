
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a new Scanner to read input from standard input
    FILE *fp = stdin;
    char buf[1024];
    int c[3][3], a[3], b[3];
    
    // Read values into the 3x3 array `c`
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            fgets(buf, sizeof(buf), fp);
            c[i][j] = atoi(buf);
        }
    }

    // Calculate the values of `b` based on the initial assumption that `a[0]` is zero
    b[0] = c[0][0] - a[0];
    b[1] = c[0][1] - a[0];
    b[2] = c[0][2] - a[0];
    
    // Calculate the values of `a` based on the values in `c`
    a[1] = c[1][0] - c[0][0];
    a[2] = c[2][0] - c[0][0];
    
    // Check if the calculated values of `a` and `c` are consistent with the given relationships
    if (a[1] == c[1][1] - c[0][1] && a[1] == c[1][2] - c[0][2] &&
        a[2] == c[2][1] - c[0][1] && a[2] == c[2][2] - c[0][2]) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    
    return 0;
}
