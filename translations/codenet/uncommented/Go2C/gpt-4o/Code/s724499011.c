#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    char *s = (char *)malloc(n * sizeof(char));
    scanf("%s", s);
    
    int *ns = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        switch (s[i]) {
            case 'R':
                ns[i] = 0;
                break;
            case 'G':
                ns[i] = 1;
                break;
            case 'B':
                ns[i] = 2;
                break;
        }
    }

    int **rgb = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        rgb[i] = (int *)malloc(3 * sizeof(int));
        if (i == 0) {
            rgb[i][0] = rgb[i][1] = rgb[i][2] = 0;
        } else {
            for (int j = 0; j < 3; j++) {
                rgb[i][j] = rgb[i - 1][j];
            }
            rgb[i][ns[i - 1]]++;
        }
    }

    int sum = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            if (ns[i] != ns[j]) {
                int tn = 3 - ns[i] - ns[j];
                sum += rgb[n][tn] - rgb[j + 1][tn];
                int k = 2 * j - i;
                if (k < n && ns[k] == tn) {
                    sum--;
                }
            }
        }
    }

    printf("%d\n", sum);

    // Free allocated memory
    free(s);
    free(ns);
    for (int i = 0; i <= n; i++) {
        free(rgb[i]);
    }
    free(rgb);

    return 0;
}

// <END-OF-CODE>
