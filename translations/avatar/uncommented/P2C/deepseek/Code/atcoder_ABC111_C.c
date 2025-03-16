#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int x[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }
    int a[n], b[n];
    int cnta[100003] = {0};
    int cntb[100003] = {0};
    int vala = 0, vala1 = 0, maxCnta = 0, maxCnta1 = 0;
    int valb = 0, valb1 = 0, maxCntb = 0, maxCntb1 = 0;
    int indexa = 0, indexb = 0;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            a[indexa++] = x[i];
        } else {
            b[indexb++] = x[i];
        }
    }

    for (int i = 0; i < indexa; i++) {
        cnta[a[i]]++;
    }
    for (int i = 0; i < indexa; i++) {
        if (maxCnta < cnta[a[i]]) {
            vala = a[i];
            maxCnta = cnta[a[i]];
        }
    }
    for (int i = 0; i < indexa; i++) {
        if (maxCnta1 < cnta[a[i]] && vala != a[i]) {
            maxCnta1 = cnta[a[i]];
            vala1 = a[i];
        }
    }

    for (int i = 0; i < indexb; i++) {
        cntb[b[i]]++;
    }
    for (int i = 0; i < indexb; i++) {
        if (maxCntb < cntb[b[i]]) {
            valb = b[i];
            maxCntb = cntb[b[i]];
        }
    }
    for (int i = 0; i < indexb; i++) {
        if (maxCntb1 < cntb[b[i]] && valb != b[i]) {
            maxCntb1 = cntb[b[i]];
            valb1 = b[i];
        }
    }

    if (valb != vala) {
        int res = 0;
        for (int i = 0; i < indexa; i++) {
            if (a[i] != vala) {
                res++;
            }
        }
        for (int i = 0; i < indexb; i++) {
            if (b[i] != valb) {
                res++;
            }
        }
        printf("%d\n", res);
    } else {
        int resa = 0, resb = 0, resa1 = 0, resb1 = 0;
        for (int i = 0; i < indexa; i++) {
            if (a[i] != vala) {
                resa++;
            }
            if (a[i] != vala1) {
                resa1++;
            }
        }
        for (int i = 0; i < indexb; i++) {
            if (b[i] != valb) {
                resb++;
            }
            if (b[i] != valb1) {
                resb1++;
            }
        }
        printf("%d\n", (resa + resb1 < resa1 + resb) ? (resa + resb1) : (resa1 + resb));
    }

    return 0;
}
