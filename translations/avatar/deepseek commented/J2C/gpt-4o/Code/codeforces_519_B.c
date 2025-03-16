#include <stdio.h>

int main() {
    // Create a variable to read the number of elements
    int n;
    
    // Read the number of elements
    scanf("%d", &n);
    
    // Initialize sums of subsets
    int a = 0, b = 0, c = 0;
    
    // Sum all n elements
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        a += temp;
    }
    
    // Sum n-1 elements
    for (int i = 0; i < n - 1; i++) {
        int temp;
        scanf("%d", &temp);
        b += temp;
    }
    
    // Sum n-2 elements
    for (int i = 0; i < n - 2; i++) {
        int temp;
        scanf("%d", &temp);
        c += temp;
    }
    
    // Calculate the differences
    int x = a - b;
    int y = b - c;
    
    // Output the results
    printf("%d\n", x);
    printf("%d\n", y);
    
    return 0;
}

// <END-OF-CODE>
