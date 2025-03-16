#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    char v[1000];
    scanf("%s", v);
    
    char *d[] = {"LEFT", "RIGHT"};
    
    int f = k - 1 < n - k;
    
    int m = (k - 1 < n - k) ? k - 1 : n - k;
    
    char a[1000][100];
    int a_index = 0;
    
    for (int i = 0; i < m; i++) {
        strcpy(a[a_index++], d[!f]);
    }
    
    for (int i = 0; i < strlen(v); i += 2 * f - 1) {
        char temp[2];
        temp[0] = v[i];
        temp[1] = '\0';
        strcpy(a[a_index++], "PRINT ");
        strcat(a[a_index++], temp);
        strcpy(a[a_index++], d[f]);
    }
    
    for (int i = 0; i < a_index - 1; i++) {
        printf("%s\n", a[i]);
    }
    
    return 0;
}

