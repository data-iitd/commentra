
#include <stdio.h>

int main() {
    int n, a[100000];
    long long sum = 0;
    
    // Read the number of elements and the list of integers from input
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    
    // Check if the sum of the list 'a' is divisible by the sum of the first n natural numbers
    if (sum % (n * (n + 1) / 2)) {
        // If not divisible, print "NO" and exit
        printf("NO\n");
    } else {
        // Calculate the average value 'k' that each element should contribute
        long long k = sum / (n * (n + 1) / 2);
        
        // Append the first element of 'a' to the end of the list to facilitate circular calculations
        a[n] = a[0];
        
        // Check if the sum of the adjusted values is zero and if all adjusted values are non-negative
        int flag = 0;
        for (int i = 0; i < n; i++) {
            if ((k - a[i] + a[i + 1]) % n || (k - a[i] + a[i + 1]) / n < 0) {
                flag = 1;
                break;
            }
        }
        
        // If either condition fails, print "NO"
        if (flag) {
            printf("NO\n");
        } else {
            // If both conditions are satisfied, print "YES"
            printf("YES\n");
        }
    }
    
    return 0;
}
