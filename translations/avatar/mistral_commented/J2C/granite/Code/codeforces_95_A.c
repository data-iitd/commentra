

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int compare(char *aa, int i, char *bb, int j, int m) {
    while (m-- > 0) {
        char a = toupper(aa[i]);
        char b = toupper(bb[j]);

        if (a!= b)
            return a - b;

        i++;
        j++;
    }

    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    char **ss = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        char s[100];
        scanf("%s", s);
        ss[i] = (char *)malloc(strlen(s) + 1);
        strcpy(ss[i], s);
    }

    char c[100];
    scanf("%s", c);
    int m = strlen(c);

    char cc[100];
    strcpy(cc, c);

    char a = (c[0] == 'a')? 'b' : 'a';
    char c_ = toupper(c[0]);
    char a_ = toupper(a);

    bool lucky[100];
    memset(lucky, 0, sizeof(lucky));

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            int l = strlen(ss[i]);

            if (m - j >= l && compare(cc, j, ss[i], 0, l) == 0) {
                for (int h = 0; h < l; h++) {
                    lucky[j + h] = true;
                }
            }
        }
    }

    for (int j = 0; j < m; j++) {
        if (lucky[j]) {
            if (tolower(cc[j]) == c[0]) {
                cc[j] = isupper(cc[j])? a_ : a;
            } else {
                cc[j] = isupper(cc[j])? c_ : c;
            }
        }
    }

    printf("%s\n", cc);

    return 0;
}

