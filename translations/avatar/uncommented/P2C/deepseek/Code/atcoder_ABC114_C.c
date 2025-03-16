#include <stdio.h>
#include <string.h>

int N;

int aaa(char *n) {
    if (atoi(n) > N) {
        return 0;
    }
    int ans = 0;
    if (strlen(n) == 3 && strchr("753", n[0]) && strchr("753", n[1]) && strchr("753", n[2])) {
        ans = 1;
    }
    for (char *p = "753"; *p != '\0'; p++) {
        char new_n[4];
        strcpy(new_n, n);
        strncat(new_n, p, 1);
        ans += aaa(new_n);
    }
    return ans;
}

int main() {
    scanf("%d", &N);
    printf("%d\n", aaa("0"));
    return 0;
}
