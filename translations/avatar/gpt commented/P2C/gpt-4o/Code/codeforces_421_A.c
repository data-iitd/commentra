#include <stdio.h>

int main() {
    int n, a, b;
    
    // Read three integers from input: n (number of elements), a, and b
    scanf("%d %d %d", &n, &a, &b);
    
    int lista[n];
    int listb[n]; // Assuming listb is also of size n, though it's not used in the original code

    // Read a list of integers from input and store it in lista
    for (int i = 0; i < a; i++) {
        scanf("%d", &lista[i]);
    }

    // Read another list of integers from input and store it in listb
    for (int i = 0; i < b; i++) {
        scanf("%d", &listb[i]);
    }

    // Iterate through the range of n (from 0 to n-1)
    for (int k = 0; k < n; k++) {
        // Check if the current index + 1 is present in lista
        int found = 0;
        for (int i = 0; i < a; i++) {
            if (lista[i] == k + 1) {
                found = 1;
                break;
            }
        }
        
        // If present, print 1 followed by a space
        if (found) {
            printf("1 ");
        } else {
            // If not present, print 2 followed by a space
            printf("2 ");
        }
    }

    return 0;
}

// <END-OF-CODE>
