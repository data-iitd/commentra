
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Main function declaration

    int n, m, r, c, answer = 0 ;
    scanf("%d %d", &n, &m) ;  // Reading the number of rows and columns in the grid
    for (int i = 0 ; i < m ; i ++ ) {
        // Reading banned cells

        scanf("%d %d", &r, &c) ;
        if (r > 1 && r < n) answer += 2 ;  // If the row is not the first or last row, add 2 to the answer
        if (c > 1 && c < n) answer += 2 ;  // If the column is not the first or last column, add 2 to the answer
    }
    answer -= n - 2 ;  // Subtracting the number of cells in the grid from the answer
    if (n % 2!= 0) answer -= 1 ;  // If the number of rows is odd, subtract 1 from the answer
    printf("%d\n", answer) ;  // Writing the answer to the output stream
    return 0 ;
}

