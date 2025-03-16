
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char s[100];

    scanf("%d %s", &n, s);

    printf("%d\n", strlen(s) - strlen(strstr(s, "ABC")));

    return 0;
}

// This is the end of the code 