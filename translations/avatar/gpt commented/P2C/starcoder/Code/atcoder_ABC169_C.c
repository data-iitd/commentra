#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read two values from input: one as an integer and the other as a float in string format
    char sa[100], sb[100];
    scanf("%s %s", sa, sb);
    
    // Convert the first value to an integer
    int a = atoi(sa);
    
    // Convert the second value to an integer representing cents (by multiplying by 100)
    int b = (int)(atof(sb) * 100 + 0.1);

    // Calculate and print the product of a and b, divided by 100 to get the final result
    printf("%d\n", a * b / 100);

    return 0;
}

