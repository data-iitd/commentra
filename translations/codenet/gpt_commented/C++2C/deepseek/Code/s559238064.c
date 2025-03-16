#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Define long long type for large integers
typedef long long ll;

// Constants for infinity and modulo operations
const int inf = 0x3f3f3f3f;
const int mod = (1 ? 1e9 + 7 : 998244353);

int main() {
    // Optimize input/output operations
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);

    // Declare variables for input and processing
    ll a, b, c, d, e, f, g, T;
    char z[100005];
    
    // Read the input string
    scanf("%s", z);
    
    // Get the size of the input string
    a = strlen(z);
    
    // Check for consecutive identical characters in the string
    for (int i = 0; i < a - 1; i++) {
        // If two consecutive characters are the same, print "Bad" and exit
        if (z[i] == z[i + 1]) {
            printf("Bad\n");
            return 0;
        }
    }
    
    // If no consecutive identical characters were found, print "Good"
    printf("Good\n");
}
