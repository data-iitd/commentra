#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int array[n + 1];
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &array[i]);
    }
    
    int odd = 0, even = 0, odd_ind = 0, even_ind = 0;
    
    for (int i = 1; i <= n; i++) {
        if (array[i] % 2 == 0) {
            even++;
            even_ind = i;
        } else {
            odd++;
            odd_ind = i;
        }
    }
    
    if (odd > even) {
        printf("%d\n", even_ind);
    } else {
        printf("%d\n", odd_ind);
    }
    
