#include <stdio.h>

int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    // The first line takes three integers n, a, and b as input.

    int lista[n];
    for (int i = 0; i < a; i++) {
        scanf("%d", &lista[i]);
    }
    // The second line takes a list of integers lista as input.

    int listb[n];
    for (int i = 0; i < b; i++) {
        scanf("%d", &listb[i]);
    }
    // The third line takes a list of integers listb as input.

    for (int k = 0; k < n; k++) {
        // The for loop iterates over the range n.
        int found = 0;
        for (int i = 0; i < a; i++) {
            if (lista[i] == k + 1) {
                found = 1;
                break;
            }
        }
        // Check if k + 1 is in lista.
        if (found) {
            // If the current index k + 1 is in the list lista,
            printf("1 ");
            // print 1 to the console.
        } else {
            // Otherwise,
            printf("2 ");
            // print 2 to the console.
        }
    }
    printf("\n");
    return 0;
}
// <END-OF-CODE>
