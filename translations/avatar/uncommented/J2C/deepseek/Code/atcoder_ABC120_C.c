#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char x[1000001];
    scanf("%s", x);
    int len = strlen(x);
    char stack[1000001];
    int top = -1;
    int c = 0;

    for (int i = 0; i < len; i++) {
        stack[++top] = x[i];
        while (top > 0) {
            char p = stack[top--];
            char q = stack[top--];
            if ((p == '1' && q == '0') || (p == '0' && q == '1')) {
                c++;
                continue;
            } else {
                stack[++top] = q;
                stack[++top] = p;
                break;
            }
        }
    }

    printf("%d\n", c * 2);
    return 0;
}
