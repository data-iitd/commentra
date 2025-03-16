#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <stdbool.h> 

int main() { 
    // Create a Scanner object for input and a PrintWriter for output
    int n; 
    scanf("%d", &n); 
    int square = n * n; 
    int loop = square / n; 
    int div = loop / 2; 
    int i, j; 
    int odd[square]; 
    int even[square]; 
    int odd_index = 0; 
    int even_index = 0; 
    for (i = 1; i <= square; i++) { 
        if (i % 2 == 0) { 
            even[even_index++] = i; 
        } else { 
            odd[odd_index++] = i; 
        } 
    } 
    for (i = 1; i <= loop; i++) { 
        for (j = 0; j < div; j++) { 
            if (i % 2 == 1) { 
                printf("%d %d ", odd[j], even[even_index - 1]); 
            } else { 
                printf("%d %d ", even[j], odd[odd_index - 1]); 
            } 
        } 
        printf("\n"); 
    } 
    return 0; 
} 
