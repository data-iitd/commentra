#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n, ans = 1, sumL = 0;
    char input[100000];
    scanf("%d", &n);
    getchar(); // to consume the newline character after the integer input
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // remove the newline character

    char *token = strtok(input, "?.!");
    while (token != NULL) {
        char *s = token;
        s = strtok(s, " ");
        while (s != NULL) {
            int L = strlen(s);
            if (L > 1) {
                if (L > n) {
                    printf("Impossible\n");
                    return 0;
                }
                if (sumL + L + (sumL > 0) > n) {
                    ans++;
                    sumL = L;
                } else {
                    sumL = sumL + L + (sumL > 0);
                }
            }
            s = strtok(NULL, " ");
        }
        token = strtok(NULL, "?.!");
    }
    printf("%d\n", ans);
    return 0;
}
