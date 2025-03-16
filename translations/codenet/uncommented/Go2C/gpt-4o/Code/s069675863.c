#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MOD 1000000007
#define MAX_LENGTH 8000
#define MAX_SUM 20000

char S[MAX_LENGTH];
int x, y;
bool dpx[MAX_LENGTH][MAX_SUM];
bool dpy[MAX_LENGTH][MAX_SUM];

int main() {
    // Read the input string
    scanf("%s", S);
    // Read x and y
    scanf("%d %d", &x, &y);

    int F[MAX_LENGTH] = {0};
    int cur = 0;
    int len = strlen(S);
    int F_index = 0;

    for (int i = 0; i < len; i++) {
        if (S[i] == 'F') {
            cur++;
        } else {
            F[F_index++] = cur;
            cur = 0;
        }
    }
    F[F_index++] = cur; // Append the last count

    int evens[MAX_LENGTH] = {0}, odds[MAX_LENGTH] = {0};
    int even_count = 0, odd_count = 0;

    for (int i = 0; i < F_index; i++) {
        if (i % 2 == 0) {
            evens[even_count++] = F[i];
        } else {
            odds[odd_count++] = F[i];
        }
    }

    dpx[0][10000] = true;
    dpy[0][10000] = true;

    for (int i = 0; i < even_count; i++) {
        int val = evens[i];
        for (int j = 2000; j <= 18000; j++) {
            if (j + val <= 18000) {
                dpx[i + 1][j + val] = dpx[i + 1][j + val] || dpx[i][j];
            }
            if (j - val >= 2000 && i != 0) {
                dpx[i + 1][j - val] = dpx[i + 1][j - val] || dpx[i][j];
            }
        }
    }

    for (int i = 0; i < odd_count; i++) {
        int val = odds[i];
        for (int j = 2000; j <= 18000; j++) {
            if (j + val <= 18000) {
                dpy[i + 1][j + val] = dpy[i + 1][j + val] || dpy[i][j];
            }
            if (j - val >= 2000) {
                dpy[i + 1][j - val] = dpy[i + 1][j - val] || dpy[i][j];
            }
        }
    }

    if (dpx[even_count][x + 10000] && dpy[odd_count][y + 10000]) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

/<END-OF-CODE>
