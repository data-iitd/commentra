

#include <stdio.h>

int main() {
    int h, a, num = 0;
    scanf("%d %d", &h, &a); // Reading input using scanf

    // Implementing a loop to subtract 'a' from 'h' until 'h' is less than or equal to 0
    for (int i = 1; h > 0; i++) {
        h = h - a; // Subtracting 'a' from 'h'
        num++; // Incrementing the counter
    }

    printf("%d", num); // Printing the result, which is the number of subtractions

    return 0;
}

