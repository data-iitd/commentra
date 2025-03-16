
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Read input values and split them into a list
    char* xxs = malloc(100 * sizeof(char));
    fgets(xxs, 100, stdin);
    char* xxs_token = strtok(xxs, " ");
    
    // Convert the input strings to integers
    int x = atoi(xxs_token);
    int t = atoi(strtok(NULL, " "));
    int a = atoi(strtok(NULL, " "));
    int b = atoi(strtok(NULL, " "));
    int da = atoi(strtok(NULL, " "));
    int db = atoi(strtok(NULL, " "));
    
    // Check if the target value x is zero
    if (x == 0) {
        printf("YES\n");  // If x is zero, print "YES" and return
        return 0;
    }
    
    // Calculate the maximum time available for a and b, constrained by t
    int a_time = (a / da) < t? (a / da) : (t - 1);
    int b_time = (b / db) < t? (b / db) : (t - 1);
    
    // Iterate through all possible values of i and j within the calculated time limits
    for (int i = 0; i <= a_time; i++) {
        for (int j = 0; j <= b_time; j++) {
            // Check if either a or b can be reduced to x by subtracting multiples of da or db
            if (a - da * i == x || b - db * j == x) {
                printf("YES\n");  // If found, print "YES" and return
                return 0;
            }
            // Check if the sum of the remaining values of a and b equals x
            if ((a - da * i) + (b - db * j) == x) {
                printf("YES\n");  // If found, print "YES" and return
                return 0;
            }
        }
    }
    
    // If no valid combination is found, print "NO"
    printf("NO\n");
    
    // Free the allocated memory
    free(xxs);
    
    return 0;
}
