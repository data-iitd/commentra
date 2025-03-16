#include <stdio.h>

int main() {
    // Declare variables for the coordinates
    int x1, y1, x2, y2;
    
    // Take input from the user and read four integers
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    
    // Calculate the differences between the coordinates
    int DIF1 = x2 - x1;
    int DIF2 = y2 - y1;
    
    // Calculate the coordinates of the other two points
    int x3 = x2 - DIF2;
    int y3 = y2 + DIF1;
    int x4 = x1 - DIF2;
    int y4 = y1 + DIF1;
    
    // Print the calculated coordinates
    printf("%d %d %d %d\n", x3, y3, x4, y4);
    
    return 0;
}

// <END-OF-CODE>
