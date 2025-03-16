#include <stdio.h>

void solve(int n) {
    // Calculating the result based on the given logic
    int result = (n / 3) * 2 + (n % 3 == 0 ? 0 : 1);
    printf("%d\n", result); // Printing the result to the console
}

int main() {
    int n;
    scanf("%d", &n); // Reading an integer input from the user and storing it in variable n
    solve(n); // Calling the solve method with the input value n
    return 0;
}

