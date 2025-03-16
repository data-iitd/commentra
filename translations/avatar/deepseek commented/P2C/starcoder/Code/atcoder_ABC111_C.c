#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int *x = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }

    int *a = (int *) malloc(n * sizeof(int));
    int *b = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            a[i] = x[i];
        } else {
            b[i] = x[i];
        }
    }

    int *cnta = (int *) malloc((100002 + 1) * sizeof(int));
    int *cntb = (int *) malloc((100002 + 1) * sizeof(int));
    for (int i = 0; i < n; i++) {
        cnta[a[i]]++;
        cntb[b[i]]++;
    }

    int vala = 0;
    int vala1 = 0;
    int maxCnta = 0;
    int maxCnta1 = 0;
    for (int i = 0; i < n; i++) {
        if (maxCnta < cnta[a[i]]) {
            vala = a[i];
            maxCnta = cnta[a[i]];
        }
    }
    for (int i = 0; i < n; i++) {
        if (maxCnta1 < cnta[a[i]] && vala!= a[i]) {
            maxCnta1 = cnta[a[i]];
            vala1 = a[i];
        }
    }

    int valb = 0;
    int valb1 = 0;
    int maxCntb = 0;
    int maxCntb1 = 0;
    for (int i = 0; i < n; i++) {
        if (maxCntb < cntb[b[i]]) {
            valb = b[i];
            maxCntb = cntb[b[i]];
        }
    }
    for (int i = 0; i < n; i++) {
        if (maxCntb1 < cntb[b[i]] && valb!= b[i]) {
            maxCntb1 = cntb[b[i]];
            valb1 = b[i];
        }
    }

    if (valb!= vala) {
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (a[i]!= vala) {
                res++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (b[i]!= valb) {
                res++;
            }
        }
        printf("%d\n", res);
    } else {
        int resa = 0;
        int resb = 0;
        int resa1 = 0;
        int resb1 = 0;
        for (int i = 0; i < n; i++) {
            if (a[i]!= vala) {
                resa++;
            }
            if (a[i]!= vala1) {
                resa1++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (b[i]!= valb) {
                resb++;
            }
            if (b[i]!= valb1) {
                resb1++;
            }
        }
        printf("%d\n", min(resa + resb1, resa1 + resb));
    }

    return 0;
}

