#include <stdio.h>

int main() {
    int n, m, s, f;
    scanf("%d %d %d %d", &n, &m, &s, &f);
    
    int d;
    char c;
    if (s < f) {
        d = 1;
        c = 'R';
    } else {
        d = -1;
        c = 'L';
    }
    
    char res[100000]; // Assuming the result will not exceed 100000 characters
    int i = 1;
    int j = s;
    int t, l, r;
    int k = 1;
    
    scanf("%d %d %d", &t, &l, &r);
    
    while (j != f) {
        if (i > t && k < m) {
            scanf("%d %d %d", &t, &l, &r);
            k++;
        }
        if (i == t && (l <= j && j <= r || l <= j + d && j + d <= r)) {
            res[i - 1] = 'X';
        } else {
            res[i - 1] = c;
            j += d;
        }
        i++;
    }
    
    res[i - 1] = '\0'; // Null-terminate the string
    printf("%s\n", res);
    
    return 0;
}

// <END-OF-CODE>
