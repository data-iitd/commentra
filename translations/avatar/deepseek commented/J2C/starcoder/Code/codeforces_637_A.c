#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    int ara[n];
    int max = 0;
    int freq[1000001];
    memset(freq, 0, sizeof(freq));
    for (int i = 0; i < n; i++) {
        scanf("%d", &ara[i]);
        freq[ara[i]]++;
        max = max > freq[ara[i]]? max : freq[ara[i]];
    }
    int max_freq = 0;
    for (int i = 0; i < n; i++) {
        if (freq[ara[i]] == max) {
            printf("%d\n", ara[i]);
            break;
        }
    }
    return 0;
}

