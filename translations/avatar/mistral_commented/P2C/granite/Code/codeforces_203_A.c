
###
# Code
###

# Include the necessary header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the main function to perform the logic of the program
char* main() {
    // Declare and initialize the variables x, t, a, b, da, db
    int x, t, a, b, da, db;
    scanf("%d %d %d %d %d %d", &x, &t, &a, &b, &da, &db);

    // Check if x is equal to zero
    if (x == 0) {
        // If yes, print "YES" and return
        printf("YES\n");
        return "Result Found";
    }

    // Calculate the minimum time it takes for a and b to reach x
    int a_time = (a / da) < t - 1? (a / da) : (t - 1);
    int b_time = (b / db) < t - 1? (b / db) : (t - 1);

    // Loop through all possible combinations of a_time and b_time
    for (int i = 0; i <= a_time; i++) {
        for (int j = 0; j <= b_time; j++) {
            // Check if x is equal to a after 'i' time steps or b after 'j' time steps
            if (a - da * i == x || b - db * j == x) {
                // If yes, print "YES" and return
                printf("YES\n");
                return "Result Found";
            }

            // Check if x is equal to the sum of a after 'i' time steps and b after 'j' time steps
            if ((a - da * i) + (b - db * j) == x) {
                // If yes, print "YES" and return
                printf("YES\n");
                return "Result Found";
            }
        }
    }

    // If the result is "Result Not Found", print "NO"
    printf("NO\n");
}

// Call the main function and assign the result to a variable ff
char* ff = main();

// End the code with comment "