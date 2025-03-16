#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    // Step 3: Input a string
    char N[100]; 
    scanf("%s", N);

    // Step 4: Calculate the sum of digits
    int S = 0;
    for (int i = 0; i < strlen(N); i++) {
        S += N[i] - '0';
    }

    // Step 5: Check if the number is divisible by the sum of its digits
    int number = atoi(N);
    if (number % S == 0) 
        printf("Yes\n");
    else 
        printf("No\n");

    // Step 6: Return 0
    return 0;
}
