

#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    scanf("%s", s);
    char *ptr = s;
    while (*ptr!= '\0') {
        if (*ptr == 'd' && *(ptr + 1) == 'r' && *(ptr + 2) == 'e' && *(ptr + 3) == 'a' && *(ptr + 4) =='m') {
            memmove(ptr, ptr + 5, strlen(ptr + 5) + 1);
        } else if (*ptr == 'e' && *(ptr + 1) == 'r' && *(ptr + 2) == 'a' && *(ptr + 3) =='s' && *(ptr + 4) == 'e') {
            memmove(ptr, ptr + 5, strlen(ptr + 5) + 1);
        } else if (*ptr == 'D' && *(ptr + 1) == 'e' && *(ptr + 2) == 'r') {
            memmove(ptr, ptr + 3, strlen(ptr + 3) + 1);
        } else if (*ptr == 'E' && *(ptr + 1) == 'r') {
            memmove(ptr, ptr + 2, strlen(ptr + 2) + 1);
        }
        ptr++;
    }
    char *result = strstrip(s);
    if (strlen(result) == 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}

// End of the code