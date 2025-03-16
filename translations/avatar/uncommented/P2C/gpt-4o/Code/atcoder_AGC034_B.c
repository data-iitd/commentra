#include <stdio.h>
#include <string.h>

int gcd(int a, int b) {
    a = a > b ? a : b;
    b = a > b ? b : a;
    while (a % b > 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return b;
}

void solve() {
    char s[100000]; // Assuming the input string won't exceed 100000 characters
    scanf("%s", s);
    char t[100000] = "";
    int i = 0;
    int len = strlen(s);
    
    while (i < len) {
        if (s[i] == 'A') {
            strcat(t, "A");
            i++;
        } else if (s[i] == 'B') {
            if (i < len - 1) {
                if (s[i + 1] == 'C') {
                    strcat(t, "D");
                    i += 2;
                } else {
                    strcat(t, "X");
                    i++;
                }
            } else {
                strcat(t, "X");
                i++;
            }
        } else {
            strcat(t, "X");
            i++;
        }
    }

    long long total = 0;
    long long numA = 0;
    for (i = 0; i < strlen(t); i++) {
        if (t[i] == 'X') {
            numA = 0;
        } else {
            if (t[i] == 'A') {
                numA++;
            } else {
                total += numA;
            }
        }
    }
    
    printf("%lld\n", total);
    long long INF = 1000000000000000000; // 10^25
    long long mod = 7 + 1000000000; // 7 + 10^9
}

int main() {
    solve();
    return 0;
}

// <END-OF-CODE>
