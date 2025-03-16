
#include <stdio.h>
#include <string.h>

int main() {
    char s[100001];  // Declare a character array to store the input string
    scanf("%s", s);  // Read input string and store it in the array

    int even0 = 0, even1 = 0, odd0 = 0, odd1 = 0;  // Initialize counters for even and odd indices

    for (int i = 0; s[i]!= '\0'; i++) {  // Iterate through the input string
        if (i % 2 == 0) {  // Check if the index is even
            if (s[i] == '0') {
                even0++;  // Increment the counter for even indexed '0's
            } else {
                even1++;  // Increment the counter for even indexed '1's
            }
        } else {  // Check if the index is odd
            if (s[i] == '0') {
                odd0++;  // Increment the counter for odd indexed '0's
            } else {
                odd1++;  // Increment the counter for odd indexed '1's
            }
        }
    }

    int option1 = strlen(s) - (even0 + odd1);  // Calculate the number of changes needed for Option 1
    int option2 = strlen(s) - (even1 + odd0);  // Calculate the number of changes needed for Option 2

    printf("%d", option1 < option2? option1 : option2);  // Print the minimum of the two options

    return 0;
}
