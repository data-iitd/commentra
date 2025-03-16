#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b;
    char line[100];

    // Read the first line from stdin and convert it to an integer
    fgets(line, sizeof(line), stdin);
    a = atoi(line);

    // Read the second line from stdin and convert it to an integer
    fgets(line, sizeof(line), stdin);
    b = atoi(line);

    // Check if the product of a and b is odd or even
    if ((a * b) % 2 != 0) {
        // If the product is odd, print "Odd" to stdout
        printf("Odd\n");
    } else {
        // If the product is even, print "Even" to stdout
        printf("Even\n");
    }

    return 0;
}
