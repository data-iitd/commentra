

#include <stdio.h>

int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    // The first line takes three integers n, a, and b as input, separated by spaces.
    int lista[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &lista[i]);
        // The second line takes a list of integers lista as input, separated by spaces.
    }
    int listb[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &listb[i]);
        // The third line takes a list of integers listb as input, separated by spaces.
    }
    for (int k = 0; k < n; k++) {
        // The for loop iterates over the range n.
        if (k + 1 == lista[k]) {
            // If the current index k + 1 is in the list lista,
            printf("1 ");
            // print 1 to the console.
        } else {
            // Otherwise,
            printf("2 ");
            // print 2 to the console.
        }
    }
    return 0;
}
