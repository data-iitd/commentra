#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char s[100];

    // Use the scanf function to read input from the standard input
    scanf("%d", &n);
    scanf("%s", s);

    // Use the strlen and strstr functions to compute and print the result
    int count = 0;
    char *ptr = s;
    while ((ptr = strstr(ptr, "ABC")) != NULL) {
        count++;
        ptr++;
    }
    printf("%d\n", count);

    return 0;
}
