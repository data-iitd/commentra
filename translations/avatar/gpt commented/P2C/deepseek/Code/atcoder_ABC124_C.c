#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char s[1000];
    int even[2] = {0}, odd[2] = {0};

    // Read input string
    scanf("%s", s);

    // Count the occurrences of '0' and '1' at even indices
    for (int i = 0; i < strlen(s); i += 2) {
        if (s[i] == '0') even[0]++;
        else even[1]++;
    }

    // Count the occurrences of '0' and '1' at odd indices
    for (int i = 1; i < strlen(s); i += 2) {
        if (s[i] == '0') odd[0]++;
        else odd[1]++;
    }

    // Calculate the minimum number of changes needed to make the string alternate
    // Option 1: Change all even indexed '0's to '1's and odd indexed '1's to '0's
    // Option 2: Change all even indexed '1's to '0's and odd indexed '0's to '1's
    // Print the minimum of the two options
    int result1 = strlen(s) - (even[0] + odd[1]);
    int result2 = strlen(s) - (even[1] + odd[0]);
    printf("%d\n", result1 < result2 ? result1 : result2);

    return 0;
}
