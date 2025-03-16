#include <stdio.h>
#include <limits.h>

int main() {
    int a;
    scanf("%d", &a);
    
    int ar[a];
    
    for (int i = 0; i < a; i++) {
        scanf("%d", &ar[i]);
    }
    
    for (int i = 0; i < a; i++) {
        int max = 0, min = 0;
        
        if (i == 0) {
            max = ar[i] - ar[0];
            min = ar[i + 1] - ar[i];
        } else if (i == a - 1) {
            max = ar[ar.length - 1] - ar[i];
            min = ar[i] - ar[i - 1];
        } else {
            max = (ar[i] - ar[0]) > (ar[ar.length - 1] - ar[i]) ? (ar[i] - ar[0]) : (ar[ar.length - 1] - ar[i]);
            min = (ar[i] - ar[i - 1]) < (ar[i + 1] - ar[i]) ? (ar[i] - ar[i - 1]) : (ar[i + 1] - ar[i]);
        }
        
        printf("%d %d\n", min, max);
    }
    
    return 0;
}
