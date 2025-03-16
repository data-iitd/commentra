
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int n, i, temp, q, w, e;
    int a[1000], b[1000];
    bool f;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        scanf("%d", &b[i]);
    }

    temp = a[0];
    q = b[0];
    w = a[0];
    e = b[0];
    f = false;

    for (i = 1; i < n; i++) {
        if (temp < a[i]) {
            if (q > b[i]) {
                f = true;
            }
            q = b[i];
            temp = a[i];
        }

        if (temp > a[i]) {
            if (q < b[i]) {
                f = true;
            }
            q = b[i];
            temp = a[i];
        }

        if (a[i] > w) {
            w = a[i];
            if (b[i] < e) {
                f = true;
            }
        }

        if (a[i] < w) {
            if (b[i] > e) {
                f = true;
            }
        }
    }

    if (f == true) {
        printf("Happy Alex\n");
    } else {
        printf("Poor Alex\n");
    }

    return EXIT_SUCCESS;
}

