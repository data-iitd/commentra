
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int compare(char *aa, int i, char *bb, int j, int m) {
    while (m-- > 0) {
        char a = toupper(aa[i]);
        char b = toupper(bb[j]);
        if (a != b) return a - b;
        i++;
        j++;
    }
    return 0;
}

void main() {
    int n;
    scanf("%d", &n);
    char **ss = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        ss[i] = (char *)malloc(100 * sizeof(char));
        scanf("%s", ss[i]);
    }
    char *cc = (char *)malloc(100 * sizeof(char));
    scanf("%s", cc);
    int m = strlen(cc);
    char c = getchar();
    char c_ = toupper(c);
    char a = c == 'a' ? 'b' : 'a';
    char a_ = toupper(a);
    int *lucky = (int *)malloc(m * sizeof(int));
    for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++) {
            int l = strlen(ss[i]);
            if (m - j >= l && compare(cc, j, ss[i], 0, l) == 0)
                for (int h = 0; h < l; h++) lucky[j + h] = 1;
        }
    for (int j = 0; j < m; j++)
        if (lucky[j]) {
            if (tolower(cc[j]) == c)
                cc[j] = isupper(cc[j]) ? a_ : a;
            else
                cc[j] = isupper(cc[j]) ? c_ : c;
        }
    printf("%s\n", cc);
}

