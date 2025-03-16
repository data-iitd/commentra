
#include <stdio.h>

int main() {
    // Read four integers from input
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    // Check conditions to determine the output
    if (c > b) {
        // If c is greater than b, output 0
        printf("0\n");
    } else if (a > d) {
        // If a is greater than d, output 0
        printf("0\n");
    } else if (a < c) {
        // If a is less than c, calculate and output the difference
        printf("%d\n", (b < d)? b : d - c);
    } else {
        // Create a list to hold the four integers
        int l[4] = {a, b, c, d};

        // Sort the list to find the second largest and third largest values
        for (int i = 0; i < 3; i++) {
            for (int j = i + 1; j < 4; j++) {
                if (l[i] > l[j]) {
                    int temp = l[i];
                    l[i] = l[j];
                    l[j] = temp;
                }
            }
        }

        // Output the difference between the second largest and third largest values
        printf("%d\n", l[2] - l[1]);
    }

    return 0;
}
