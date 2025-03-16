#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int len;
    scanf("%d", &len);
    int a[len];
    for (int i = 0; i < len; i++) {
        scanf("%d", &a[i]);
    }
    int l = 0;
    int r = 0;
    bool flag = false;
    bool isTrue = false;
    for (int i = 0; i < len; i++) {
        if (a[i]!= i + 1 &&!flag) {
            l = i + 1;
            flag = true;
            continue;
        }
        if (a[i]!= i + 1 && flag) {
            r = i + 1;
            if ((a[r - 1] - a[r - 2] > 0)) {
                isTrue = true;
                break;
            }
        }
    }
    printf("%d %d\n", (!isTrue)? l : 0, (!isTrue)? r : 0);
    return 0;
}

