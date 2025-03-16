
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);
    int ara[n];
    int max = 0;
    int freq[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &ara[i]);
        if (freq[ara[i]] == 0) {
            freq[ara[i]] = 1;
        } else {
            freq[ara[i]]++;
        }
        if (freq[ara[i]] > max) {
            max = freq[ara[i]];
        }
    }
    for (int i = 0; i < n; i++) {
        if (freq[ara[i]] == max) {
            printf("%d\n", ara[i]);
            break;
        }
    }
    return 0;
}

