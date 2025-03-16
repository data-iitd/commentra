
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char x[100001];
    fgets(x, 100001, stdin);
    int c = 0;
    int s[100001];
    int t = 0;
    for (int i = 0; i < strlen(x) - 1; i++) {
        s[t++] = x[i] - '0';
        while (t > 1) {
            if ((s[t - 1] == 0 && s[t - 2] == 1) || (s[t - 1] == 1 && s[t - 2] == 0)) {
                c++;
                t -= 2;
            } else {
                break;
            }
        }
    }
    printf("%d\n", c * 2);
    return 0;
}
