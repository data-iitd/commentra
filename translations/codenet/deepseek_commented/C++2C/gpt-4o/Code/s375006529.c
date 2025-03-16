#include <stdio.h>
#include <string.h>

int main() {
    // Step 1: Reading the Input
    char s[100]; // Assuming the maximum length of the string is 99
    scanf("%s", s);

    // Step 2: Calculating the Size of the String
    int n = strlen(s);

    // Step 3: Initializing an Array to Count Character Frequencies
    int v[26] = {0};

    // Step 4: Counting Character Frequencies
    for (int i = 0; i < n; i++) {
        v[s[i] - 'a']++;
    }

    // Step 5: Determining the Result
    char *ans = "Yes";
    for (int i = 0; i < 26; i++) {
        if (v[i] % 2 != 0) {
            ans = "No";
            break;
        }
    }

    // Step 6: Outputting the Result
    printf("%s\n", ans);
    
    return 0;
}

// <END-OF-CODE>
