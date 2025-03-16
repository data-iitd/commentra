
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char x[100001];
    scanf("%s", x);
    int n = strlen(x);
    int a1 = 0, a2 = 0;
    for (int i = 1; i < n; i++) {
        if (x[i] == x[i - 1]) {
            x[i] = x[i] == '1'? '0' : '1';
            a1++;
        }
    }
    for (int i = n - 1; i > 0; i--) {
        if (x[i] == x[i - 1]) {
            x[i - 1] = x[i - 1] == '1'? '0' : '1';
            a2++;
        }
    }
    printf("%d\n", a1 < a2? a1 : a2);
    return 0;
}
// END-OF-CODE