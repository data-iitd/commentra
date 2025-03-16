
#include <stdio.h>

int sub(int a, int b) {
    int min = a < b? a : b;
    int max = a > b? a : b;
    int result = 0;
    
    while (min > 0) {
        result += max / min;
        max = max % min;
        
        int curr_min = min;
        min = max;
        max = curr_min;
    }
    
    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        
        printf("%d\n", sub(a, b));
    }
    
    return 0;
}

