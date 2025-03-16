
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char* f(char* s) {
    char* r = (char*)malloc(100 * sizeof(char));
    int j = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i]!= '-' && s[i]!= ';' && s[i]!= '_') {
            r[j] = tolower(s[i]);
            j++;
        }
    }
    r[j] = '\0';
    return r;
}

int main() {
    char* l[3];
    for (int i = 0; i < 3; i++) {
        char s[100];
        scanf("%s", s);
        l[i] = f(s);
    }
    int n;
    scanf("%d", &n);
    char** t = (char**)malloc(6 * sizeof(char*));
    int k = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            for (int m = j + 1; m < 3; m++) {
                t[k] = (char*)malloc(100 * sizeof(char));
                sprintf(t[k], "%s%s%s", l[i], l[j], l[m]);
                k++;
                t[k] = (char*)malloc(100 * sizeof(char));
                sprintf(t[k], "%s%s%s", l[i], l[m], l[j]);
                k++;
                t[k] = (char*)malloc(100 * sizeof(char));
                sprintf(t[k], "%s%s%s", l[j], l[i], l[m]);
                k++;
                t[k] = (char*)malloc(100 * sizeof(char));
                sprintf(t[k], "%s%s%s", l[j], l[m], l[i]);
                k++;
                t[k] = (char*)malloc(100 * sizeof(char));
                sprintf(t[k], "%s%s%s", l[m], l[i], l[j]);
                k++;
                t[k] = (char*)malloc(100 * sizeof(char));
                sprintf(t[k], "%s%s%s", l[m], l[j], l[i]);
                k++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        char s[100];
        scanf("%s", s);
        int flag = 0;
        for (int j = 0; j < 6 * k; j++) {
            if (strcmp(f(s), t[j]) == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            printf("ACC\n");
        } else {
            printf("WA\n");
        }
    }
    return 0;
}

// END-OF-CODE