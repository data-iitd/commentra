#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void solve() {
    char s[100001];
    scanf("%s", s);
    char t[100001];
    int i = 0;
    int len = strlen(s);
    while (i < len) {
        if (s[i] == 'A') {
            t[i] = 'A';
            i++;
        } else if (s[i] == 'B') {
            if (i < len - 1) {
                if (s[i + 1] == 'C') {
                    t[i] = 'D';
                    i += 2;
                } else {
                    t[i] = 'X';
                    i++;
                }
            } else {
                t[i] = 'X';
                i++;
            }
        } else {
            t[i] = 'X';
            i++;
        }
    }
    t[i] = '\0'; // Null-terminate the string

    int total = 0;
    int numA = 0;
    for (i = 0; i < len; i++) {
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
    printf("%d\n", total);
}

int main() {
    solve();
    return 0;
}
