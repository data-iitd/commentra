#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void println(char *cc, int m) {
    for (int i = 0; i < m; i++) {
        putchar(cc[i]);
    }
    putchar('\n');
}

int compare(char *aa, int i, char *bb, int j, int m) {
    while (m-- > 0) {
        char a = toupper(aa[i]);
        char b = toupper(bb[j]);

        if (a != b)
            return a - b;

        i++;
        j++;
    }

    return 0;
}

void main() {
    int n;
    scanf("%d", &n);
    char *ss[n];

    for (int i = 0; i < n; i++) {
        char temp[100];
        scanf("%s", temp);
        ss[i] = (char *)malloc((strlen(temp) + 1) * sizeof(char));
        strcpy(ss[i], temp);
    }

    char cc[100];
    scanf("%s", cc);
    int m = strlen(cc);

    char c;
    getchar(); // Consume the newline character after reading the number of arrays
    c = getchar();
    char c_ = toupper(c);
    char a = (c == 'a') ? 'b' : 'a';
    char a_ = toupper(a);

    int lucky[m];
    memset(lucky, 0, m * sizeof(int));

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            int l = strlen(ss[i]);

            if (m - j >= l && compare(cc, j, ss[i], 0, l) == 0) {
                for (int h = 0; h < l; h++) {
                    lucky[j + h] = 1;
                }
            }
        }
    }

    for (int j = 0; j < m; j++) {
        if (lucky[j]) {
            if (islower(cc[j]) && tolower(cc[j]) == c) {
                cc[j] = (isupper(cc[j])) ? a_ : a;
            } else {
                cc[j] = (isupper(cc[j])) ? c_ : c;
            }
        }
    }

    println(cc, m);

    for (int i = 0; i < n; i++) {
        free(ss[i]);
    }
}

