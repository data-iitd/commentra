#include <stdio.h>

int main() {
    char B, OUT;
    scanf(" %c", &B);
    if (B == 'A') OUT = 'T';
    else if (B == 'T') OUT = 'A';
    else if (B == 'C') OUT = 'G';
    else OUT = 'C';
    printf("%c\n", OUT);
    return 0;
}

// <END-OF-CODE>
