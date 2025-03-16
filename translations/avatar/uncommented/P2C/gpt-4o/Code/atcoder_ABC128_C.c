#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100
#define MAX_M 100
#define MAX_COMB 1000

int n, m;
int li[MAX_M][MAX_N];
int p[MAX_N];
int q[MAX_N];
int v[MAX_N];
int q_size = 0;
int v_size = 0;

void generate_combinations(int *arr, int n, int r, int start, int index, int *data, int i, int *count) {
    if (index == r) {
        int valid = 1;
        for (int j = 0; j < m; j++) {
            int count_odd = 0;
            for (int k = 0; k < r; k++) {
                if (arr[data[k]] == li[j][0]) {
                    count_odd++;
                }
            }
            if (count_odd % 2 != p[j]) {
                valid = 0;
                break;
            }
        }
        if (valid) {
            (*count) += 1;
        }
        return;
    }
    for (int j = start; j <= n - 1 && n - j + 1 >= r - index; j++) {
        data[index] = j;
        generate_combinations(arr, n, r, j + 1, index + 1, data, i, count);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < m; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &li[i][j]);
        }
    }
    
    for (int i = 0; i < m; i++) {
        scanf("%d", &p[i]);
    }
    
    int present[MAX_N] = {0};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < MAX_N && li[i][j] != 0; j++) {
            present[li[i][j]] = 1;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (!present[i]) {
            v[v_size++] = i;
        }
    }
    
    int ans = 0;
    for (int i = 0; i <= q_size; i++) {
        int data[MAX_COMB];
        generate_combinations(q, q_size, i, 0, 0, data, 0, &ans);
    }
    
    printf("%d\n", ans);
    return 0;
}
