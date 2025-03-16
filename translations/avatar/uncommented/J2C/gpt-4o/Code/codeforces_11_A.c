#include <stdio.h>

int main() {
    int n, d;
    scanf("%d %d", &n, &d);
    int nums[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    
    int result = 0;
    int a = 0;
    
    for (int i = 1; i < n; i++) {
        a = (nums[i - 1] - nums[i]);
        if (a >= 0) {
            result += a / d + 1;
            nums[i] += (a / d + 1) * d;
        }
    }
    
    printf("%d\n", result);
    return 0;
}

// <END-OF-CODE>
