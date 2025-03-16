#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void compare(char *aa, int i, char *bb, int j, int m, int *result) {
    while (m-- > 0) {
        char a = toupper(aa[i]);
        char b = toupper(bb[j]);
        if (a != b) {
            *result = a - b;
            return;
        }
        i++;
        j++;
    }
    *result = 0;
}

int main() {
    int n;
    scanf("%d", &n);
    
    char **ss = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        char buffer[100]; // Assuming max length of each string is 99
        scanf("%s", buffer);
        ss[i] = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(ss[i], buffer);
    }
    
    char cc[100]; // Assuming max length of cc is 99
    scanf("%s", cc);
    int m = strlen(cc);
    
    char c;
    scanf(" %c", &c);
    char c_ = toupper(c);
    char a = (c == 'a') ? 'b' : 'a';
    char a_ = toupper(a);
    
    int *lucky = (int *)calloc(m, sizeof(int));
    
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            int l = strlen(ss[i]);
            int result;
            if (m - j >= l) {
                compare(cc, j, ss[i], 0, l, &result);
                if (result == 0) {
                    for (int h = 0; h < l; h++) {
                        lucky[j + h] = 1;
                    }
                }
            }
        }
    }
    
    for (int j = 0; j < m; j++) {
        if (lucky[j]) {
            if (tolower(cc[j]) == c) {
                cc[j] = isupper(cc[j]) ? a_ : a;
            } else {
                cc[j] = isupper(cc[j]) ? c_ : c;
            }
        }
    }
    
    printf("%s\n", cc);
    
    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(ss[i]);
    }
    free(ss);
    free(lucky);
    
    return 0;
}

// <END-OF-CODE>
