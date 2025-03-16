#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
<<<<<<< HEAD
    char N[100]; // Assuming the maximum length of the input string is 99
=======
    char N[100]; // Assuming the maximum length of the input number is 99
>>>>>>> 98c87cb78a (data updated)
    scanf("%s", N);
    
    int S = 0;
    for (int i = 0; i < strlen(N); i++) {
        S += N[i] - '0';
    }
    
    if (atoi(N) % S == 0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    
    return 0;
}

// <END-OF-CODE>
