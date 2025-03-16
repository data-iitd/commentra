#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100002

int main() {
    int n;
    scanf("%d", &n);

    int x[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }

    int a[n], b[n];
    int cnta[MAX_SIZE] = {0};
    int cntb[MAX_SIZE] = {0};
    int vala = 0, valb = 0;
    int maxCnta = 0, maxCntb = 0;
    int maxCnta1 = 0, vala1 = 0;
    int maxCntb1 = 0, valb1 = 0;

    int a_size = 0, b_size = 0;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            a[a_size++] = x[i];
        } else {
            b[b_size++] = x[i];
        }
    }

    for (int i = 0; i < a_size; i++) {
        cnta[a[i]]++;
    }

    for (int i = 0; i < a_size; i++) {
        if (maxCnta < cnta[a[i]]) {
            vala = a[i];
            maxCnta = cnta[a[i]];
        }
    }

    for (int i = 0; i < a_size; i++) {
        if (maxCnta1 < cnta[a[i]] && a[i] != vala) {
            maxCnta1 = cnta[a[i]];
            vala1 = a[i];
        }
    }

    for (int i = 0; i < b_size; i++) {
        cntb[b[i]]++;
    }

    for (int i = 0; i < b_size; i++) {
        if (maxCntb < cntb[b[i]]) {
            valb = b[i];
            maxCntb = cntb[b[i]];
        }
    }

    for (int i = 0; i < b_size; i++) {
        if (maxCntb1 < cntb[b[i]] && b[i] != valb) {
            maxCntb1 = cntb[b[i]];
            valb1 = b[i];
        }
    }

    if (valb != vala) {
        int res = 0;
        for (int i = 0; i < a_size; i++) {
            if (a[i] != vala) {
                res++;
            }
        }
        for (int i = 0; i < b_size; i++) {
            if (b[i] != valb) {
                res++;
            }
        }
        printf("%d\n", res);
    } else {
        int resa = 0, resb = 0, resa1 = 0, resb1 = 0;
        for (int i = 0; i < a_size; i++) {
            if (a[i] != vala) {
                resa++;
            }
            if (a[i] != vala1) {
                resa1++;
            }
        }
        for (int i = 0; i < b_size; i++) {
            if (b[i] != valb) {
                resb++;
            }
            if (b[i] != valb1) {
                resb1++;
            }
        }
        printf("%d\n", min(resa + resb1, resa1 + resb));
    }

    return 0;
}
