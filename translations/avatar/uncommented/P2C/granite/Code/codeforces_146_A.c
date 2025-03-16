
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char number[n];
    scanf("%s", number);
    int h1 = 0, h2 = 0;
    for (int i = 0; i < n; i++) {
        if (number[i]!= '4' && number[i]!= '7') {
            printf("NO");
            return 0;
        }
        if (i < n / 2) {
            h1 += number[i] - '0';
        } else {
            h2 += number[i] - '0';
        }
    }
    if (h1 == h2) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}
