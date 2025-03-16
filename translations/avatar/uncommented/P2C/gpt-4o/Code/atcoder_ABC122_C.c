#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count(int total, char *s, int i) {
    return (s[i - 1] == 'A' && s[i] == 'C') ? total + 1 : total;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    
    char *s = (char *)malloc((n + 1) * sizeof(char));
    scanf("%s", s);
    
    int *problems = (int *)malloc(q * 2 * sizeof(int));
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &problems[i * 2], &problems[i * 2 + 1]);
    }
    
    int *cumsum = (int *)malloc(n * sizeof(int));
    cumsum[0] = 0;
    
    for (int i = 1; i < n; i++) {
        cumsum[i] = count(cumsum[i - 1], s, i);
    }
    
    for (int i = 0; i < q; i++) {
        int l = problems[i * 2];
        int r = problems[i * 2 + 1];
        printf("%d\n", cumsum[r - 1] - cumsum[l - 1]);
    }
    
    free(s);
    free(problems);
    free(cumsum);
    
    return 0;
}

// <END-OF-CODE>
