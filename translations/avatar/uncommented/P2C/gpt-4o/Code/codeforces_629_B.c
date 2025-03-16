#include <stdio.h>

int main() {
    int N = 368;
    int m[368] = {0};
    int f[368] = {0};
    int num_inputs;
    
    scanf("%d", &num_inputs);
    for (int i = 0; i < num_inputs; i++) {
        char x;
        int a, b;
        scanf(" %c %d %d", &x, &a, &b);
        b += 1; // Increment b by 1 as in the original code
        
        if (x == 'M') {
            m[a] += 2;
            m[b] -= 2;
        } else {
            f[a] += 2;
            f[b] -= 2;
        }
    }
    
    int a_sum = 0, b_sum = 0, c = 0;
    for (int i = 0; i < N; i++) {
        a_sum += m[i];
        b_sum += f[i];
        if (a_sum < b_sum && a_sum > c) {
            c = a_sum;
        } else if (b_sum < a_sum && b_sum > c) {
            c = b_sum;
        }
    }
    
    printf("%d\n", c);
    return 0;
}

// <END-OF-CODE>
