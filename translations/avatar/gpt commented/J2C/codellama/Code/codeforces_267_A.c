#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sub(int a, int b);

int main() {
    int n, a, b, min, max, result;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        
        min = a < b ? a : b;
        max = a > b ? a : b;
        
        result = 0;
        
        while (min > 0) {
            result += max / min;
            max = max % min;
            
            int curr_min = min < max ? min : max;
            int curr_max = min > max ? min : max;
            min = curr_min;
            max = curr_max;
        }
        
        printf("%d\n", result);
    }
    
    return 0;
}

int sub(int a, int b) {
    int min = a < b ? a : b;
    int max = a > b ? a : b;
    
    int result = 0;
    
    while (min > 0) {
        result += max / min;
        max = max % min;
        
        int curr_min = min < max ? min : max;
        int curr_max = min > max ? min : max;
        min = curr_min;
        max = curr_max;
    }
    
    return result;
}

