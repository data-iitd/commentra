#include <stdio.h>
#include <string.h>

int main() {
<<<<<<< HEAD
    char z[100001]; // Assuming a maximum length for the input string
=======
    char z[100001]; // Assuming the maximum length of the string is 100000
>>>>>>> 98c87cb78a (data updated)
    scanf("%s", z);
    int a = strlen(z);
    
    for (int i = 0; i < a - 1; i++) {
        if (z[i] == z[i + 1]) {
            printf("Bad\n");
            return 0;
        }
    }
    printf("Good\n");
    return 0;
}

// <END-OF-CODE>
