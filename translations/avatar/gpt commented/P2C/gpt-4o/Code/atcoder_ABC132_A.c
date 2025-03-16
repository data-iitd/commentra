#include <stdio.h>
#include <string.h>

int main() {
    // Take input string from the user
    char S[100]; // Assuming the input string will not exceed 99 characters
    scanf("%s", S);

    // Create an array to count occurrences of characters (assuming only lowercase letters)
    int count[26] = {0};
    int unique_count = 0;

    // Count the frequency of each character in the string
    for (int i = 0; S[i] != '\0'; i++) {
        if (count[S[i] - 'a'] == 0) {
            unique_count++; // New unique character found
        }
        count[S[i] - 'a']++;
    }

    // Check if the number of unique characters is not equal to 2
    if (unique_count != 2) {
        // If there are not exactly 2 unique characters, print "No" and exit
        printf("No\n");
        return 0;
    }

    // Check if both characters appear exactly twice
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0 && count[i] != 2) {
            // If any character does not appear exactly twice, print "No" and exit
            printf("No\n");
            return 0;
        }
    }

    // If both conditions are satisfied, print "Yes"
    printf("Yes\n");
    return 0;
}
