#include <stdio.h>
#include <string.h>

int N;

int contains753(char *n) {
    int has3 = 0, has5 = 0, has7 = 0;
    for (int i = 0; i < strlen(n); i++) {
        if (n[i] == '3') has3 = 1;
        else if (n[i] == '5') has5 = 1;
        else if (n[i] == '7') has7 = 1;
    }
    return has3 && has5 && has7;
}

int aaa(char *n) {
    int num = atoi(n);
    if (num > N) {
        return 0;
    }
    int ans = contains753(n) ? 1 : 0;
    char next[2] = {0, 0};
    for (char i = '7'; i <= '5'; i--) {
        next[0] = i;
        strcat(n, next);
        ans += aaa(n);
        n[strlen(n) - 1] = '\0'; // Remove the last character added
    }
    return ans;
}

int main() {
    scanf("%d", &N);
    char n[100] = "0"; // Initialize with "0"
    printf("%d\n", aaa(n));
    return 0;
}

// <END-OF-CODE>
