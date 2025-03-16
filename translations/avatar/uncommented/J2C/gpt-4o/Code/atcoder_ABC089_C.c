#include <stdio.h>
#include <string.h>

int main() {
    int n;
    long cnt[5] = {0}; // M, A, R, C, H

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        char str[100]; // Assuming the maximum length of the string is 99
        scanf("%s", str);
        switch (str[0]) {
            case 'M': cnt[0]++; break;
            case 'A': cnt[1]++; break;
            case 'R': cnt[2]++; break;
            case 'C': cnt[3]++; break;
            case 'H': cnt[4]++; break;
        }
    }

    long res = cnt[0] * cnt[1] * cnt[2] +
               cnt[0] * cnt[1] * cnt[3] +
               cnt[0] * cnt[1] * cnt[4] +
               cnt[0] * cnt[2] * cnt[3] +
               cnt[0] * cnt[2] * cnt[4] +
               cnt[0] * cnt[3] * cnt[4] +
               cnt[1] * cnt[2] * cnt[3] +
               cnt[1] * cnt[2] * cnt[4] +
               cnt[1] * cnt[3] * cnt[4] +
               cnt[2] * cnt[3] * cnt[4];

    printf("%ld\n", res);
    return 0;
}

// <END-OF-CODE>
