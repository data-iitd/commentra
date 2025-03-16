#include <stdio.h>
#include <string.h>

int main(){
    int n; // Declare an integer variable to store the number of test cases
    scanf("%d", &n); // Read the value of n from the standard input

    int ac_count = 0; // Initialize an integer variable to count AC submissions
    int wa_count = 0; // Initialize an integer variable to count WA submissions
    int tle_count = 0; // Initialize an integer variable to count TLE submissions
    int re_count = 0; // Initialize an integer variable to count RE submissions

    // Loop through each test case
    for (int i = 0; i < n; ++i){
        char s[10]; // Declare a string variable to store the result of a test case
        scanf("%s", s); // Read the result from the standard input
        if (strcmp(s, "AC") == 0){ // Check if the result is AC
            ac_count += 1; // Increment the AC count
        } else if (strcmp(s, "WA") == 0){ // Check if the result is WA
            wa_count += 1; // Increment the WA count
        } else if (strcmp(s, "TLE") == 0){ // Check if the result is TLE
            tle_count += 1; // Increment the TLE count
        } else if (strcmp(s, "RE") == 0){ // Check if the result is RE
            re_count += 1; // Increment the RE count
        }
    }

    // Print the counts of each result type
    printf("AC x %d\n", ac_count);
    printf("WA x %d\n", wa_count);
    printf("TLE x %d\n", tle_count);
    printf("RE x %d\n", re_count);
}

