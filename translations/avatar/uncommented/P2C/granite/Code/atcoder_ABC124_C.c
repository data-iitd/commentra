
#include <stdio.h>
#include <string.h>

int main() {
    char s[100001];
    scanf("%s", s);
    int even[2] = {0}, odd[2] = {0};
    for (int i = 0; s[i]!= '\0'; i++) {
        if (i % 2 == 0) {
            even[s[i] - '0']++;
        } else {
            odd[s[i] - '0']++;
        }
    }
    printf("%d\n", (even[0] + odd[1]) < (even[1] + odd[0])? (even[0] + odd[1]) : (even[1] + odd[0]));
    return 0;
}
// END-OF-CODE