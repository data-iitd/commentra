#include <stdio.h>

int main() {
    int n, a, b;
    
    // Assigning the values of input variables to n, a, and b
    scanf("%d %d %d", &n, &a, &b);
    
    int lista[n];
    int listb[n]; // Assuming listb is needed for future use, though not used in the provided code

    // Creating two lists, lista and listb, from the input
    for (int i = 0; i < n; i++) {
        scanf("%d", &lista[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &listb[i]);
    }

    // Iterating through the range of n
    for (int k = 0; k < n; k++) {
        // Checking if k+1 is present in the lista list
        int found = 0;
        for (int j = 0; j < n; j++) {
            if (lista[j] == k + 1) {
                found = 1;
                break;
            }
        }
        // Printing 1 if k+1 is present in the lista list
        if (found) {
            printf("1 ");
        } else {
            // Printing 2 if k+1 is not present in the lista list
            printf("2 ");
        }
    }
    
    return 0;
}
// <END-OF-CODE>
