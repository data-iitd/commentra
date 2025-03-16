#include <stdio.h>
#include <string.h>

int main() {
    int a, t = 0, h = 0, lt, lh, l;
    scanf("%d", &a);
<<<<<<< HEAD
    char taro[100], hana[100]; // Assuming max length of names is 99 characters
=======
    char taro[100], hana[100]; // Assuming max length of strings is 99 characters
>>>>>>> 98c87cb78a (data updated)

    for (int i = 0; i < a; ++i) {
        scanf("%s %s", taro, hana);
        lt = strlen(taro);
        lh = strlen(hana);
        
        if (lt > lh) {
            l = lt;
        } else {
            l = lh;
        }

        if (strcmp(taro, hana) > 0) {
            t += 3;
        } else if (strcmp(hana, taro) > 0) {
            h += 3;
        } else if (strcmp(hana, taro) == 0) {
            h += 1;
            t += 1;
        }
    }
    printf("%d %d\n", t, h);

    return 0;
}

// <END-OF-CODE>
