
#include <stdio.h>

int main() {
    char a[4];
    scanf("%s", a);
    char ans[] = "Good";
    for (int i = 0; i < 3; i++) {
        if (a[i] == a[i+1]) {
            ans = "Bad";
        }
    }
    printf("%s\n", ans);
    return 0;
}
// 