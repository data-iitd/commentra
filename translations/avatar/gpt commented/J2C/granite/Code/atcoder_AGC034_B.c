
#include <stdio.h>
#include <string.h>

int main() {
    // Read the input string and replace occurrences of "BC" with "D"
    char s[100001];
    fgets(s, 100001, stdin);
    char *p = strstr(s, "BC");
    while (p!= NULL) {
        memmove(p, p + 1, strlen(p + 1) + 1);
        p = strstr(s, "BC");
    }

    // Initialize counters for 'A' and the result
    long long cnt = 0;
    long long tmp = 0;

    // Iterate through the modified string to count occurrences
    for (int i = 0; i < strlen(s); i++) {
        // Increment temporary counter for 'A'
        if (s[i] == 'A') {
            tmp++;
        }
        // Add the count of 'A's to the result when 'D' is encountered
        else if (s[i] == 'D') {
            cnt += tmp;
        }
        // Reset the temporary counter for any other character
        else {
            tmp = 0;
        }
    }

    // Output the final count of valid pairs
    printf("%lld\n", cnt);

    return 0;
}
