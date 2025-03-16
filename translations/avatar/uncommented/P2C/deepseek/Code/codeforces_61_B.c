#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX_LEN 100

char* f(char* s) {
    char* r = (char*)malloc(MAX_LEN * sizeof(char));
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != '-' && s[i] != ';' && s[i] != '_') {
            r[j++] = tolower(s[i]);
        }
    }
    r[j] = '\0';
    return r;
}

void solve() {
    char* l[3];
    for (int i = 0; i < 3; i++) {
        l[i] = (char*)malloc(MAX_LEN * sizeof(char));
        scanf("%s", l[i]);
        l[i] = f(l[i]);
    }

    char** t = (char**)malloc(6 * sizeof(char*));
    for (int i = 0; i < 6; i++) {
        t[i] = (char*)malloc(MAX_LEN * sizeof(char));
    }

    int index = 0;
    for (int i1 = 0; i1 < 3; i1++) {
        for (int i2 = 0; i2 < 3; i2++) {
            if (i2 != i1) {
                for (int i3 = 0; i3 < 3; i3++) {
                    if (i3 != i1 && i3 != i2) {
                        sprintf(t[index], "%s%s%s", l[i1], l[i2], l[i3]);
                        index++;
                    }
                }
            }
        }
    }

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char* s = (char*)malloc(MAX_LEN * sizeof(char));
        scanf("%s", s);
        s = f(s);
        int found = 0;
        for (int j = 0; j < 6; j++) {
            if (strcmp(s, t[j]) == 0) {
                found = 1;
                break;
            }
        }
        if (found) {
            printf("ACC\n");
        } else {
            printf("WA\n");
        }
        free(s);
    }

    for (int i = 0; i < 6; i++) {
        free(t[i]);
    }
    free(t);
    for (int i = 0; i < 3; i++) {
        free(l[i]);
    }
}

int main() {
    solve();
    return 0;
}
