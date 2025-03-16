
#include <stdio.h>

int main() {
    // Read an integer from standard input and return it
    int ii1() {
        int x;
        scanf("%d", &x);
        return x;
    }

    // Read a string from standard input and return it
    char* is1() {
        char x[1000];
        scanf("%s", x);
        return x;
    }

    // Read a list of integers from standard input and return it
    int* iia() {
        int x[1000];
        for (int i = 0; i < 1000; i++) {
            scanf("%d", &x[i]);
        }
        return x;
    }

    // Read a list of strings from standard input and return it, split by spaces
    char** isa() {
        char* x[1000];
        for (int i = 0; i < 1000; i++) {
            scanf("%s", x[i]);
        }
        return x;
    }

    // Set the value of k from standard input
    int k = ii1();

    // Initialize a variable t to 0
    int t = 0;

    // Loop from 1 to k
    for (int i = 1; i <= k; i++) {
        // Calculate the value of t using the current value of i and k
        t = ( (t % k) * 10 + 7 ) % k;

        // Check if t is a multiple of k
        if (t == 0) {
            // Print the value of i and break out of the loop
            printf("%d\n", i);
            break;
        }
    }

    // If the loop completes without finding a multiple of k, print -1
    if (t!= 0) {
        printf("-1\n");
    }

    return 0;
}
