#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void generate_combinations(int *arr, int n, int r, int **combinations, int *count) {
    int *data = (int *)malloc(r * sizeof(int));
    int i;
    
    void combination_util(int *arr, int n, int r, int index, int *data, int i) {
        if (index == r) {
            combinations[*count] = (int *)malloc(r * sizeof(int));
            for (int j = 0; j < r; j++) {
                combinations[*count][j] = data[j];
            }
            (*count)++;
            return;
        }
        if (i >= n) return;
        data[index] = arr[i];
        combination_util(arr, n, r, index + 1, data, i + 1);
        combination_util(arr, n, r, index, data, i + 1);
    }
    
    combination_util(arr, n, r, 0, data, 0);
    free(data);
}

int main() {
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);
    
    int **c = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        c[i] = (int *)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            scanf("%d", &c[i][j]);
        }
    }
    
    int *pre = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        pre[i] = i;
    }
    
    int **combinations = (int **)malloc((1 << n) * sizeof(int *));
    int count = 0;
    
    for (int i = 1; i <= n; i++) {
        generate_combinations(pre, n, i, combinations, &count);
    }
    
    int ans = INT_MAX;
    
    for (int i = 0; i < m; i++) {
        int *rem = (int *)malloc(count * sizeof(int));
        int rem_count = 0;
        
        for (int j = 0; j < count; j++) {
            int ca = 0;
            for (int k = 0; k < (j + 1); k++) {
                ca += c[combinations[j][k]][i];
            }
            if (ca < x) {
                rem[rem_count++] = j;
            }
        }
        
        for (int j = rem_count - 1; j >= 0; j--) {
            free(combinations[rem[j]]);
            combinations[rem[j]] = combinations[count - 1];
            count--;
        }
        
        free(rem);
        
        if (count == 0) {
            printf("-1\n");
            for (int i = 0; i < n; i++) {
                free(c[i]);
            }
            free(c);
            free(pre);
            free(combinations);
            return 0;
        }
    }
    
    for (int i = 0; i < count; i++) {
        int ca = 0;
        for (int j = 0; j < (i + 1); j++) {
            ca += c[combinations[i][j]][0];
        }
        if (ca < ans) {
            ans = ca;
        }
    }
    
    printf("%d\n", ans);
    
    for (int i = 0; i < n; i++) {
        free(c[i]);
    }
    free(c);
    free(pre);
    for (int i = 0; i < count; i++) {
        free(combinations[i]);
    }
    free(combinations);
    
    return 0;
}

// <END-OF-CODE>
