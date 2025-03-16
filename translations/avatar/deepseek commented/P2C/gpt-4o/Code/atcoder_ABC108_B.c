#include <stdio.h>

int main() {
    // 1. Declare variables for input coordinates
    int x1, y1, x2, y2;
    
    // 2. Take input from the user
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    
    // 3. Calculate the differences
    int DIF1 = x2 - x1;
    int DIF2 = y2 - y1;
    
    // 4. Calculate new coordinates
    int x3 = x2 - DIF2;
    int y3 = y2 + DIF1;
    int x4 = x1 - DIF2;
    int y4 = y1 + DIF1;
    
    // 5. Print the coordinates
    printf("%d %d %d %d\n", x3, y3, x4, y4);
    
    return 0;
}

// <END-OF-CODE>
