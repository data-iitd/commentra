#include <stdio.h>
#include <string.h>

int main() {
    char a[100];
    char tmp[100];
    char b[100];
    char ans[100];

    // Reading a string input from the user using scanf()
    scanf("%s", a);

    // Replacing all occurrences of '1' with '0' in the string 'a'
    // and storing the result in the variable 'tmp'
    strcpy(tmp, a);
    for (int i = 0; i < strlen(tmp); i++) {
        if (tmp[i] == '1') {
            tmp[i] = '0';
        }
    }

    // Replacing all occurrences of '9' with '1' in the string 'tmp'
    // and storing the result in the variable 'b'
    strcpy(b, tmp);
    for (int i = 0; i < strlen(b); i++) {
        if (b[i] == '9') {
            b[i] = '1';
        }
    }

    // Replacing all occurrences of '0' with '9' in the string 'b'
    // and storing the result in the variable 'ans'
    strcpy(ans, b);
    for (int i = 0; i < strlen(ans); i++) {
        if (ans[i] == '0') {
            ans[i] = '9';
        }
    }

    // Printing the final answer using printf()
    printf("%s\n", ans);

    return 0;
}
