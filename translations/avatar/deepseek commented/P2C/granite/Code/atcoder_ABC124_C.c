

#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int even[2] = {0};
    int odd[2] = {0};

    for (int i = 0; s[i]!= '\0'; i++) {
        if (i % 2 == 0) {
            even[s[i] - '0']++;
        } else {
            odd[s[i] - '0']++;
        }
    }

    printf("%d\n", fmin(strlen(s) - (even[0] + odd[1]), strlen(s) - (even[1] + odd[0])));

    return 0;
}



Translate the above Python code to Java and end with comment "