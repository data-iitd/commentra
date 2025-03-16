#include <stdio.h>
#include <string.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    char v[100]; // Assuming the input string will not exceed 100 characters
    scanf("%s", v);
    
    const char *d[] = {"LEFT", "RIGHT"};
    int f = (k - 1 < n - k);
    int m = (k - 1 < n - k) ? (k - 1) : (n - k);
    
    char a[200][50]; // Assuming a maximum of 200 commands, each up to 50 characters
    int index = 0;
    
    for (int i = 0; i < m; i++) {
        strcpy(a[index++], d[!f]);
    }
    
    for (int i = (f ? 0 : strlen(v) - 1); (f ? i < strlen(v) : i >= 0); (f ? i++ : i--)) {
        sprintf(a[index++], "PRINT %c", v[i]);
        strcpy(a[index++], d[f]);
    }
    
    for (int i = 0; i < index - 1; i++) {
        printf("%s\n", a[i]);
    }
    
    return 0;
}

// <END-OF-CODE>
