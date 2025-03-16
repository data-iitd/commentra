#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000

int main() {
    int n;
    scanf("%d", &n);

    int ara[MAX_N];
    int freq[MAX_N] = {0};

    for (int i = 0; i < n; i++) {
        scanf("%d", &ara[i]);
        freq[ara[i]]++;
    }

    int max_freq = 0;
    for (int i = 0; i < MAX_N; i++) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
        }
    }

    int order[MAX_N] = {0};
    int order_index = 0;

    for (int i = 0; i < n; i++) {
        if (order[ara[i]] == 0) {
            order[ara[i]] = freq[ara[i]];
            if (order[ara[i]] == max_freq) {
                printf("%d\n", ara[i]);
                break;
            }
        } else {
            order[ara[i]]++;
            if (order[ara[i]] == max_freq) {
                printf("%d\n", ara[i]);
                break;
            }
        }
    }

    return 0;
}
