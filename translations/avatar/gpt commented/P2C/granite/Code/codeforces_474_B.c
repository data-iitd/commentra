
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize an empty list to store the sequence
    int L[100000];
    int L_size = 0;

    // Read input (not used, but could be for prompting the user)
    char buf[1024];
    fgets(buf, sizeof(buf), stdin);

    // Initialize a variable 'r' to keep track of the current number to be added to the list
    int r = 1;

    // Read a line of input, split it into parts, and iterate over each part
    char *p = buf;
    while (*p) {
        char *q = p;
        while (*q && *q!='') q++;
        *q = '\0';
        int k = atoi(p);
        // Extend the list 'L' by adding 'r' for 'k' times
        for (int i = 0; i < k; i++) {
            L[L_size++] = r;
        }
        // Increment 'r' for the next number
        r++;
        p = q + 1;
    }

    // Read another line of input (not used, but could be for prompting the user)
    fgets(buf, sizeof(buf), stdin);

    // Read a line of input, split it into parts, and iterate over each part
    p = buf;
    while (*p) {
        char *q = p;
        while (*q && *q!='') q++;
        *q = '\0';
        int j = atoi(p);
        // Print the element from list 'L' at the index specified by 'j' (adjusted for 0-based index)
        printf("%d\n", L[j - 1]);
        p = q + 1;
    }

    return 0;
}
