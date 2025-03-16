#include <stdio.h>
#include <string.h>

int main() {
<<<<<<< HEAD
    char s[100]; // Assuming the maximum length of the input string is 100
=======
    char s[100], t[100];
>>>>>>> 98c87cb78a (data updated)
    scanf("%s", s);
    
    int len = strlen(s);
    if (len > 2) {
<<<<<<< HEAD
        printf("%c%d%c\n", s[0], len - 2, s[len - 1]);
    } else if (len == 2) {
        printf("%c1%c\n", s[0], s[1]);
    } else if (len == 1) {
        printf("%c0%c\n", s[0], s[0]);
    }

=======
        sprintf(t, "%c%d%c", s[0], len - 2, s[len - 1]);
    } else {
        // If the string length is 2 or less, we just copy it to t
        strcpy(t, s);
    }
    
    printf("%s\n", t);
>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// <END-OF-CODE>
