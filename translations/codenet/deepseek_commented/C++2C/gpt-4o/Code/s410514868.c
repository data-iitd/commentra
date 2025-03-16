#include <stdio.h>
#include <string.h>

typedef long long ll;

int main(void) {
    ll n, k, ans = 0, ans2 = 0, cnt = 0;
    char s[100001]; // Assuming the maximum length of the string is 100000

    // Reading the input values for n and k, and the string s
    scanf("%lld %lld", &n, &k);
    scanf("%s", s);
    
    // Initializing L with the first character of s
    char L = s[0];
    
    // Loop through the string starting from the second character
    for (int i = 1; i < n; i++) {
        // If the current character is the same as L, increment cnt
        if (L == s[i]) {
            cnt++;
        } else {
            // Update L to the new character, add cnt to ans, increment ans2, and reset cnt
            L = s[i];
            ans += cnt;
            ans2++;
            cnt = 0;
        }
    }
    
    // Add the final count to ans and increment ans2
    ans += cnt;
    ans2++;
    
    // Calculate the output as ans + min(2*k, ans2-1) and print it
    printf("%lld\n", ans + (2 * k < ans2 - 1 ? 2 * k : ans2 - 1));

    return 0;
}

// <END-OF-CODE>
