#include <stdio.h>

int main() {
    int n;
    char s[100001]; // Assuming the maximum length of s is 100000
    scanf("%d %s", &n, s);

    int max = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'I') {
            cnt++;
        } else {
            cnt--;
        }

        if (cnt > max) {
            max = cnt;
        }
    }

    printf("%d\n", max);
    return 0;
}

// <END-OF-CODE>
