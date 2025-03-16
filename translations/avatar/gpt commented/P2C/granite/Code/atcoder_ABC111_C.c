
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int x[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }

    int a[n / 2], b[n / 2];
    int i = 0, j = 0;
    for (int k = 0; k < n; k++) {
        if (k % 2 == 0) {
            a[i] = x[k];
            i++;
        } else {
            b[j] = x[k];
            j++;
        }
    }

    int cnta[100002 + 1] = {0}, cntb[100002 + 1] = {0};
    for (int k = 0; k < n / 2; k++) {
        cnta[a[k]]++;
        cntb[b[k]]++;
    }

    int vala = 0, vala1 = 0, maxCnta = 0, maxCnta1 = 0;
    for (int k = 0; k <= 100002; k++) {
        if (maxCnta < cnta[k]) {
            vala = k;
            maxCnta = cnta[k];
        }
        if (maxCnta1 < cnta[k] && vala!= k) {
            maxCnta1 = cnta[k];
            vala1 = k;
        }
    }

    int valb = 0, valb1 = 0, maxCntb = 0, maxCntb1 = 0;
    for (int k = 0; k <= 100002; k++) {
        if (maxCntb < cntb[k]) {
            valb = k;
            maxCntb = cntb[k];
        }
        if (maxCntb1 < cntb[k] && valb!= k) {
            maxCntb1 = cntb[k];
            valb1 = k;
        }
    }

    if (valb!= vala) {
        int res = 0;
        for (int k = 0; k < n / 2; k++) {
            if (a[k]!= vala) {
                res++;
            }
            if (b[k]!= valb) {
                res++;
            }
        }
        printf("%d\n", res);
    } else {
        int resa = 0, resa1 = 0, resb = 0, resb1 = 0;
        for (int k = 0; k < n / 2; k++) {
            if (a[k]!= vala) {
                if (a[k]!= vala1) {
                    resa1++;
                } else {
                    resa++;
                }
            }
            if (b[k]!= valb) {
                if (b[k]!= valb1) {
                    resb1++;
                } else {
                    resb++;
                }
            }
        }
        printf("%d\n", resa + resb1 < resa1 + resb? resa + resb1 : resa1 + resb);
    }

    return 0;
}
