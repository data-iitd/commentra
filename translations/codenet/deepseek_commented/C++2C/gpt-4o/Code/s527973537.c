#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Step 3: Input a string
<<<<<<< HEAD
    char N[100]; // Assuming the maximum length of the input string is 99
=======
    char N[100]; 
>>>>>>> 98c87cb78a (data updated)
    scanf("%s", N);

    // Step 4: Calculate the sum of digits
    int S = 0;
    for (int i = 0; i < strlen(N); i++) {
        S += N[i] - '0';
    }

    // Step 5: Check if the number is divisible by the sum of its digits
    if (atoi(N) % S == 0) 
        printf("Yes\n");
    else 
        printf("No\n");

    // Step 6: Return 0
    return 0;
}

// <END-OF-CODE>
