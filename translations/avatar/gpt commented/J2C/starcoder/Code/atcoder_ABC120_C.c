#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char x[100000];
    scanf("%s", x);
    int c = 0;
    int i = 0;
    char p, q;
    while (x[i]!= '\0') {
        if (x[i] == '1' && x[i + 1] == '0') {
            c++;
            i += 2;
        } else if (x[i] == '0' && x[i + 1] == '1') {
            c++;
            i += 2;
        } else {
            i++;
        }
    }
    printf("%d\n", c * 2);
    return 0;
}
