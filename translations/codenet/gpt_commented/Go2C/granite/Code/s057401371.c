
#include <stdio.h>
#include <ctype.h>

int main() {
    int c;
    while ((c = getchar())!= EOF) {
        if (isupper(c)) {
            putchar(c + 'a' - 'A');
        } else if (islower(c)) {
            putchar(c - 'a' + 'A');
        } else {
            putchar(c);
        }
    }
    return 0;
}
