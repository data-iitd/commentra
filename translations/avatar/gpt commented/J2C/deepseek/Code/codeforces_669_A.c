#include <stdio.h>
#include <stdlib.h>

void solve(int n) {
    // Calculating and printing the result based on the input integer n
    // The formula calculates (n / 3) * 2 and adds 1 if n is not divisible by 3
    printf("%d\n", (n / 3) * 2 + (n % 3 == 0 ? 0 : 1));
}

int main() {
    int n;
    
    // Reading an integer input from the user
    scanf("%d", &n);
    
    // Calling the solve method with the input integer
    solve(n);
    
    return 0;
}
