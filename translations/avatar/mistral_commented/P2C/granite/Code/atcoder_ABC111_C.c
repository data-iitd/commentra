
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int x[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }

    int a[n/2], b[n/2];
    int j = 0, k = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            a[j] = x[i];
            j++;
        } else {
            b[k] = x[i];
            k++;
        }
    }

    int cnta[100002 + 1] = {0};
    int cntb[100002 + 1] = {0};

    for (int i = 0; i < n/2; i++) {
        cnta[a[i]]++;
        cntb[b[i]]++;
    }

    int vala = 0, valb = 0;
    int maxCnta = 0, maxCntb = 0;

    for (int i = 0; i < n/2; i++) {
        if (maxCnta < cnta[a[i]]) {
            vala = a[i];
            maxCnta = cnta[a[i]];
        }
        if (maxCntb < cntb[b[i]]) {
            valb = b[i];
            maxCntb = cntb[b[i]];
        }
    }

    int vala1 = 0, valb1 = 0;
    int maxCnta1 = 0, maxCntb1 = 0;

    for (int i = 0; i < n/2; i++) {
        if (maxCnta1 < cnta[a[i]] && a[i]!= vala) {
            vala1 = a[i];
            maxCnta1 = cnta[a[i]];
        }
        if (maxCntb1 < cntb[b[i]] && b[i]!= valb) {
            valb1 = b[i];
            maxCntb1 = cntb[b[i]];
        }
    }

    if (valb!= vala) {
        int res = 0;
        for (int i = 0; i < n/2; i++) {
            if (a[i]!= vala) {
                res++;
            }
            if (b[i]!= valb) {
                res++;
            }
        }
        printf("%d\n", res);
    } else {
        int resa = 0, resa1 = 0;
        for (int i = 0; i < n/2; i++) {
            if (a[i]!= vala) {
                resa++;
            }
            if (a[i]!= vala1) {
                resa1++;
            }
        }
        int resb = 0, resb1 = 0;
        for (int i = 0; i < n/2; i++) {
            if (b[i]!= valb) {
                resb++;
            }
            if (b[i]!= valb1) {
                resb1++;
            }
        }
        printf("%d\n", (resa + resb1) < (resa1 + resb)? (resa + resb1) : (resa1 + resb));
    }

    return 0;
}
