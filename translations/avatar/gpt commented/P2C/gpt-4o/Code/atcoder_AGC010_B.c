#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int a[n];
    long long sum_a = 0;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum_a += a[i];
    }
    
    long long sum_n = n * (n + 1) / 2;
    
    // Check if the sum of the list 'a' is divisible by the sum of the first n natural numbers
    if (sum_a % sum_n != 0) {
        // If not divisible, print "NO" and exit
        printf("NO\n");
        return 0;
    }
    
    // Calculate the average value 'k' that each element should contribute
    double k = (double)sum_a / sum_n;
    
    // Append the first element of 'a' to the end of the list to facilitate circular calculations
    int a_extended[n + 1];
    for (int i = 0; i < n; i++) {
        a_extended[i] = a[i];
    }
    a_extended[n] = a[0];
    
    // Check if the sum of the adjusted values is zero and if all adjusted values are non-negative
    int sum_adjusted_non_negative = 0;
    int sum_adjusted = 0;
    
    for (int i = 1; i <= n; i++) {
        double adjusted_value = k - a_extended[i] + a_extended[i - 1];
        sum_adjusted += (int)adjusted_value % n;
        if (adjusted_value / n >= 0) {
            sum_adjusted_non_negative++;
        }
    }
    
    if (sum_adjusted != 0 || sum_adjusted_non_negative != n) {
        // If either condition fails, print "NO"
        printf("NO\n");
    } else {
        // If both conditions are satisfied, print "YES"
        printf("YES\n");
    }
    
    return 0;
}

// <END-OF-CODE>
