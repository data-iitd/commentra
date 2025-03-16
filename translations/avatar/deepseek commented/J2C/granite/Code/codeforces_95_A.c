
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int compare(char *aa, int i, char *bb, int j, int m) {
    while (m-- > 0) {
        char a = toupper(aa[i]);
        char b = toupper(bb[j]);
        if (a!= b) return a - b;
        i++;
        j++;
    }
    return 0;
}

int main() {
    // Reading the number of strings and the array of strings
    int n;
    scanf("%d", &n);
    char *ss[n];
    for (int i = 0; i < n; i++) {
        ss[i] = (char *)malloc(101 * sizeof(char));
        scanf("%s", ss[i]);
    }

    // Reading the pattern array and the target character
    char cc[101];
    scanf("%s", cc);
    int m = strlen(cc);
    char c;
    scanf(" %c", &c);
    char c_ = toupper(c);
    char a = (c == 'a')? 'b' : 'a';
    char a_ = toupper(a);

    // Array to mark positions in cc that match any string in ss
    bool lucky[m];
    memset(lucky, 0, m * sizeof(bool));

    // Finding lucky positions and updating characters based on the target character c
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

    // Updating characters in cc based on the lucky positions and target character c
    for (int j = 0; j < m; j++) {
        if (lucky[j]) {
            if (tolower(cc[j]) == c) {
                cc[j] = isupper(cc[j])? a_ : a;
            } else {
                cc[j] = isupper(cc[j])? c_ : c;
            }
        }
    }

    // Printing the modified cc array
    printf("%s\n", cc);

    // Freeing memory for dynamically allocated strings
    for (int i = 0; i < n; i++) {
        free(ss[i]);
    }

    return 0;
}
