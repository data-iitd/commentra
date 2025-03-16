
#include <stdio.h>
#include <string.h>

int main() {
    long a;
    char b[100];
    scanf("%ld %s", &a, b);
    char *p = b;
    while (*p!= '\0') {
        if (*p == '.') {
            *p = '\0';
            break;
        }
        p++;
    }
    int bInt = atoi(b);
    long result = (a * bInt) / 100;
    printf("%ld\n", result);
    return 0;
}
// END-OF-CODE