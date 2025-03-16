
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    // Step 1: Reading the Input
    char s[100001];
    scanf("%s", s);

    // Step 2: Calculating the Size of the String
    int n = strlen(s);

    // Step 3: Initializing an Array to Count Character Frequencies
    int v[26] = {};

    // Step 4: Counting Character Frequencies
    for (int i = 0; i < n; i++) {
        v[s[i] - 'a']++;
    }

    // Step 5: Determining the Result
    char ans[10] = "Yes";
    for (int i = 0; i < 26; i++) {
        if (v[i] % 2!= 0) {
            strcpy(ans, "No");
            break;
        }
    }

    // Step 6: Outputting the Result
    printf("%s\n", ans);
}
