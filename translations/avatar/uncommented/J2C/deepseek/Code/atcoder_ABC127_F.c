#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int t;
    scanf("%d", &t);
    int min = 0;
    long sumMin = 0, sumMax = 0, sumb = 0;
    int pqmin[t], pqmax[t];
    int pqminSize = 0, pqmaxSize = 0;

    while (t-- > 0) {
        char s[10];
        scanf("%s", s);
        if (s[0] == '2') {
            long ans = min;
            ans *= pqminSize;
            ans -= sumMin;
            long ans1 = min;
            ans1 *= pqmaxSize;
            ans1 = sumMax - ans1;
            printf("%d %ld\n", min, ans + ans1 + sumb);
        } else {
            int in;
            long num;
            scanf("%d %ld", &in, &num);
            sumb += num;
            if (in > min) {
                pqmax[pqmaxSize++] = in;
                sumMax += in;
            } else {
                pqmin[pqminSize++] = in;
                sumMin += in;
            }
            qsort(pqmin, pqminSize, sizeof(int), compare);
            qsort(pqmax, pqmaxSize, sizeof(int), compare);

            if (pqminSize > pqmaxSize) {
                sumMax += pqmin[pqminSize - 1];
                sumMin -= pqmin[pqminSize - 1];
                pqmax[pqmaxSize++] = pqmin[--pqminSize];
            }
            if (pqminSize < pqmaxSize) {
                sumMax -= pqmax[pqmaxSize - 1];
                sumMin += pqmax[pqmaxSize - 1];
                pqmin[pqminSize++] = pqmax[--pqmaxSize];
            }
            min = pqmin[0];
        }
    }
    return 0;
}
