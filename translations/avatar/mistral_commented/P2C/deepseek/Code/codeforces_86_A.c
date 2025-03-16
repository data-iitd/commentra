#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    int l, r;
    scanf("%d %d", &l, &r);

    int curr = r;
    int s = 0;
    int ans = -1;

    while (curr) {
        s += 1;
        int first = (int)pow(10, s);
        int second = first / 2;

        int range[] = {l, r, first, second};
        for (int i = 0; i < 4; i++) {
            if (range[i] >= l && range[i] <= r) {
                curr = range[i];
                char rev[10];
                sprintf(rev, "%d", curr);
                int len = strlen(rev);
                for (int j = 0; j < len; j++) {
                    rev[j] = '9' - rev[j] + '0';
                }
                int reversed = atoi(rev);
                if (reversed * curr > ans) {
                    ans = reversed * curr;
                }
            }
        }
        curr--;
    }

    printf("%d\n", ans);
    return 0;
}

