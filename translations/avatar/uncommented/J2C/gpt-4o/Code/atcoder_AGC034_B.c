#include <stdio.h>
#include <string.h>

void solve(int testNumber) {
    char s[100000]; // Assuming the maximum length of the string is 100000
    scanf("%s", s);
    
    // Replace "BC" with "D"
    char temp[100000];
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'B' && s[i + 1] == 'C') {
            temp[j++] = 'D';
            i++; // Skip the next character
        } else {
            temp[j++] = s[i];
        }
    }
    temp[j] = '\0'; // Null-terminate the new string

    long cnt = 0;
    long tmp = 0;
    for (int i = 0; temp[i] != '\0'; i++) {
        if (temp[i] == 'A') {
            tmp++;
        } else if (temp[i] == 'D') {
            cnt += tmp;
        } else {
            tmp = 0;
        }
    }
    printf("%ld\n", cnt);
}

int main() {
    int testNumber = 1; // Assuming a single test case
    solve(testNumber);
    return 0;
}

// <END-OF-CODE>
