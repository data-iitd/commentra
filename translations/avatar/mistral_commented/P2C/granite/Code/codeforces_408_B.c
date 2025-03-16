
###
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
###

###
#define MAX_SIZE 100000
#define MOD 100000007
###

###
typedef struct {
    int count;
    char color;
} Color;
###

###
int compareColors(const void *a, const void *b) {
    Color *c1 = (Color *)a;
    Color *c2 = (Color *)b;

    if (c1->color < c2->color) {
        return -1;
    } else if (c1->color > c2->color) {
        return 1;
    } else {
        return 0;
    }
}
###

###
int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        char bought[MAX_SIZE];
        scanf("%s", bought);

        char made[MAX_SIZE];
        scanf("%s", made);

        Color boughtColors[26];
        Color madeColors[26];

        int boughtCount = 0;
        int madeCount = 0;

        for (int i = 0; bought[i]!= '\0'; i++) {
            int index = bought[i] - 'A';
            if (boughtColors[index].color == 0) {
                boughtColors[index].color = bought[i];
                boughtColors[index].count = 1;
                boughtCount++;
            } else {
                boughtColors[index].count++;
            }
        }

        for (int i = 0; made[i]!= '\0'; i++) {
            int index = made[i] - 'A';
            if (madeColors[index].color == 0) {
                madeColors[index].color = made[i];
                madeColors[index].count = 1;
                madeCount++;
            } else {
                madeColors[index].count++;
            }
        }

        if (boughtCount!= madeCount) {
            printf("-1\n");
        } else {
            qsort(boughtColors, 26, sizeof(Color), compareColors);
            qsort(madeColors, 26, sizeof(Color), compareColors);

            int result = 0;
            for (int i = 0; i < 26; i++) {
                if (boughtColors[i].color!= madeColors[i].color) {
                    printf("-1\n");
                    break;
                } else {
                    result += (boughtColors[i].count < madeColors[i].count)? boughtColors[i].count : madeColors[i].count;
                }
            }

            printf("%d\n", result);
        }
    }

    return 0;
}
###

Translate the above C code to Java and end with comment "