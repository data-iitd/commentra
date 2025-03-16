
#include <stdio.h>
#include <string.h>

int N;

int aaa(char *n) {
    if (atoi(n) > N) {
        return 0;
    }
    int ans = 1;
    if (strlen(n) == 1 && n[0] == '0') {
        return 0;
    }
    if (strlen(n) == 1 && n[0]!= '0') {
        return 1;
    }
    if (strlen(n) > 1 && n[0]!= '0') {
        ans = 1;
    }
    if (strlen(n) > 1 && n[0] == '0') {
        return 0;
    }
    if (strlen(n) > 1 && n[0] == '7' && n[1]!= '0') {
        ans += aaa(strcat(n, "5"));
    }
    if (strlen(n) > 1 && n[0] == '7' && n[1] == '0') {
        return 0;
    }
    if (strlen(n) > 1 && n[0] == '5' && n[1]!= '0') {
        ans += aaa(strcat(n, "3"));
    }
    if (strlen(n) > 1 && n[0] == '5' && n[1] == '0') {
        return 0;
    }
    if (strlen(n) > 1 && n[0] == '3' && n[1]!= '0') {
        ans += aaa(strcat(n, "7"));
    }
    if (strlen(n) > 1 && n[0] == '3' && n[1] == '0') {
        return 0;
    }
    return ans;
}

int main() {
    scanf("%d", &N);
    printf("%d\n", aaa("0"));
    return 0;
}
