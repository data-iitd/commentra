#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int a[n + 1];
    int sum = 0;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    
    // Calculate the expected sum
    int expected_sum = n * (n + 1) / 2;
    
    if (sum % expected_sum != 0) {
        printf("NO\n");
    } else {
        double k = (double)sum / expected_sum;
        a[n] = a[0]; // a[n] is a[0] for the wrap-around
        
        int valid = 1;
        int count = 0;
        
        for (int i = 1; i <= n; i++) {
            double diff = (k - a[i] + a[i - 1]);
            if ((int)diff % n != 0) {
                valid = 0;
                break;
            }
            if (diff / n < 0) {
                valid = 0;
                break;
            }
            count++;
        }
        
        if (!valid || count != n) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
    
    return 0;
}

// <END-OF-CODE>
