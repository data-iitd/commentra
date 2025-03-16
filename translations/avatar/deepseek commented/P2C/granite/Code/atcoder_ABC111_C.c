
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);  // Read an integer n from input
    int x[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);  // Read a list of integers x from input
    }

    // Split the list x into two lists, a and b, based on their indices (even and odd)
    int a[n / 2];
    int b[n / 2];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            a[j] = x[i];
            j++;
        } else {
            b[j] = x[i];
            j++;
        }
    }

    // Initialize two lists to count the frequency of each element in a and b
    int cnta[100002 + 1] = {0};
    int cntb[100002 + 1] = {0};

    // Find the most frequent element in list a and its first and second most frequent elements
    int vala = 0;
    int vala1 = 0;
    int maxCnta = 0;
    int maxCnta1 = 0;
    for (int i = 0; i < n / 2; i++) {
        cnta[a[i]]++;
    }
    for (int i = 0; i < n / 2; i++) {
        if (maxCnta < cnta[a[i]]) {
            vala = a[i];
            maxCnta = cnta[a[i]];
        }
    }
    for (int i = 0; i < n / 2; i++) {
        if (maxCnta1 < cnta[a[i]] && vala!= a[i]) {
            maxCnta1 = cnta[a[i]];
            vala1 = a[i];
        }
    }

    // Find the most frequent element in list b and its first and second most frequent elements
    int valb = 0;
    int valb1 = 0;
    int maxCntb = 0;
    int maxCntb1 = 0;
    for (int i = 0; i < n / 2; i++) {
        cntb[b[i]]++;
    }
    for (int i = 0; i < n / 2; i++) {
        if (maxCntb < cntb[b[i]]) {
            valb = b[i];
            maxCntb = cntb[b[i]];
        }
    }
    for (int i = 0; i < n / 2; i++) {
        if (maxCntb1 < cntb[b[i]] && valb!= b[i]) {
            maxCntb1 = cntb[b[i]];
            valb1 = b[i];
        }
    }

    // Compare the most frequent elements of a and b
    int res = 0;
    if (valb!= vala) {
        for (int i = 0; i < n / 2; i++) {
            if (a[i]!= vala) {
                res++;
            }
        }
        for (int i = 0; i < n / 2; i++) {
            if (b[i]!= valb) {
                res++;
            }
        }
    } else {
        int resa = 0;
        int resb = 0;
        int resa1 = 0;
        int resb1 = 0;
        for (int i = 0; i < n / 2; i++) {
            if (a[i]!= vala) {
                resa++;
            }
            if (a[i]!= vala1) {
                resa1++;
            }
        }
        for (int i = 0; i < n / 2; i++) {
            if (b[i]!= valb) {
                resb++;
            }
            if (b[i]!= valb1) {
                resb1++;
            }
        }
        res = (resa + resb1 < resa1 + resb)? (resa + resb1) : (resa1 + resb);
    }

    printf("%d\n", res);  // Print the result

    return 0;
}
