
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char x[100001];
    scanf("%s", x);
    int c = 0;
    int s[100001];
    int top = -1;
    for (int i = 0; x[i]!= '\0'; i++) {
        s[++top] = x[i] - '0';
        while (top > 0 && s[top - 1]!= s[top]) {
            c += 2;
            top -= 2;
        }
    }
    printf("%d\n", c);
    return 0;
}
//END-OF-CODE