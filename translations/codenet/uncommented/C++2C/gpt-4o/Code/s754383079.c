#include <stdio.h>
#include <string.h>
<<<<<<< HEAD
#include <algorithm>
=======
#include <limits.h>
>>>>>>> 98c87cb78a (data updated)

const int M = 1010;
char a[M], b[M];
int n, m, ans = M + 10;

int main() {
    scanf("%s", a + 1);
    n = strlen(a + 1);
    scanf("%s", b + 1);
    m = strlen(b + 1);
    
    for (int i = 1; i + m - 1 <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= m; j++) {
            if (a[i + j - 1] != b[j]) {
                sum++;
            }
        }
<<<<<<< HEAD
        ans = std::min(ans, sum);
=======
        if (sum < ans) {
            ans = sum;
        }
>>>>>>> 98c87cb78a (data updated)
    }
    
    printf("%d\n", ans);
    
    return 0;
}

// <END-OF-CODE>
