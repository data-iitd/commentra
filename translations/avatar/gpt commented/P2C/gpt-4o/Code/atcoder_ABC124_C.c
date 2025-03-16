#include <stdio.h>
#include <string.h>

int main() {
    char s[100];  // Assuming the input string will not exceed 99 characters
    scanf("%s", s);  // Read the input string

    int even0 = 0, even1 = 0;  // Counters for even indices
    int odd0 = 0, odd1 = 0;    // Counters for odd indices

    // Count occurrences of '0' and '1' at even and odd indices
    for (int i = 0; s[i] != '\0'; i++) {
        if (i % 2 == 0) {  // Even index
            if (s[i] == '0') even0++;
            else if (s[i] == '1') even1++;
        } else {  // Odd index
            if (s[i] == '0') odd0++;
            else if (s[i] == '1') odd1++;
        }
    }

    int length = strlen(s);
    
    // Calculate the minimum number of changes needed to make the string alternate
    int option1 = length - (even0 + odd1);  // Change all even indexed '0's to '1's and odd indexed '1's to '0's
    int option2 = length - (even1 + odd0);  // Change all even indexed '1's to '0's and odd indexed '0's to '1's

    // Print the minimum of the two options
    printf("%d\n", option1 < option2 ? option1 : option2);

    return 0;
}
