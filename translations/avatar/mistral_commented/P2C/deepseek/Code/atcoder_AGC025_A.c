#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char n[100];
    char *a[] = {"10", "100", "1000", "10000", "100000"};
    int new;

    // Take an input from the user and assign it to the variable 'n'
    scanf("%s", n);

    // Convert each character of the input 'n' to an integer using the 'map' function
    // and then sum up all the integers using the 'sum' function and assign the result to the variable 'new'
    new = 0;
    for (int i = 0; i < strlen(n); i++) {
        new += n[i] - '0';
    }

    // Check if the input 'n' is present in the list 'a'
    int found = 0;
    for (int i = 0; i < 5; i++) {
        if (strcmp(n, a[i]) == 0) {
            found = 1;
            break;
        }
    }

    // If the input 'n' is present in the list 'a', then print the number 10
    if (found) {
        printf("10\n");
    } else {
        // If the input 'n' is not present in the list 'a', then print the value of the variable 'new'
        printf("%d\n", new);
    }

    return 0;
}
