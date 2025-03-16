
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int **li = (int **)malloc(sizeof(int *) * m);
    for (int i = 0; i < m; i++) {
        li[i] = (int *)malloc(sizeof(int) * (n - 1));
        for (int j = 0; j < n - 1; j++) {
            scanf("%d", &li[i][j]);
        }
    }
    
    int *p = (int *)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &p[i]);
    }
    
    int *q = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        q[i] = 0;
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            q[li[i][j]] = 1;
        }
    }
    
    int *v = (int *)malloc(sizeof(int) * n);
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (q[i] == 0) {
            v[count] = i;
            count++;
        }
    }
    
    int ans = 0;
    for (int i = 0; i < pow(2, count); i++) {
        int *s = (int *)malloc(sizeof(int) * count);
        for (int j = 0; j < count; j++) {
            s[j] = 0;
        }
        
        int k = i;
        for (int j = 0; j < count; j++) {
            s[j] = k % 2;
            k /= 2;
        }
        
        int flag = 1;
        for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int k = 0; k < count; k++) {
                if (s[k] == 1) {
                    sum += q[li[j][k]];
                }
            }
            if (sum % 2!= p[j]) {
                flag = 0;
                break;
            }
        }
        
        if (flag == 1) {
            ans++;
        }
    }
    
    printf("%d\n", ans);
    
    for (int i = 0; i < m; i++) {
        free(li[i]);
    }
    free(li);
    free(p);
    free(q);
    free(v);
    
    return 0;
}

