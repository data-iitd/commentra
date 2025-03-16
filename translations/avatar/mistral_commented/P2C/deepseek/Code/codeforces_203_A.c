#include <stdio.h>
#include <stdlib.h>

int main() {
    // Input the string of numbers separated by spaces and split it into a list
    int xxs[6];
    char buffer[100];
    fgets(buffer, sizeof(buffer), stdin);
    char *token = strtok(buffer, " ");
    int index = 0;
    while (token != NULL) {
        xxs[index++] = atoi(token);
        token = strtok(NULL, " ");
    }

    // Extract the first six numbers as integers and assign them to variables x, t, a, b, da, db respectively
    int x = xxs[0], t = xxs[1], a = xxs[2], b = xxs[3], da = xxs[4], db = xxs[5];

    // Check if x is equal to zero
    if (x == 0) {
        // If yes, print "YES" and return
        printf("YES\n");
        return 0;
    }

    // Calculate the minimum time it takes for a and b to reach x
    int a_time = (a / da) < (t - 1) ? (a / da) : (t - 1);
    int b_time = (b / db) < (t - 1) ? (b / db) : (t - 1);

    // Loop through all possible combinations of a_time and b_time
    for (int i = 0; i <= a_time; i++) {
        for (int j = 0; j <= b_time; j++) {
            // Check if x is equal to a after 'i' time steps or b after 'j' time steps
            if (a - i * da == x || b - j * db == x) {
                // If yes, print "YES" and return
                printf("YES\n");
                return 0;
            }

            // Check if x is equal to the sum of a after 'i' time steps and b after 'j' time steps
            if ((a - i * da) + (b - j * db) == x) {
                // If yes, print "YES" and return
                printf("YES\n");
                return 0;
            }
        }
    }

    // If the result is "Result Not Found", print "NO"
    printf("NO\n");
    return 0;
}
