#include <stdio.h>
<<<<<<< HEAD
=======
#include <string.h>
>>>>>>> 98c87cb78a (data updated)

int main() {
    char str[100]; // Assuming the input string will not exceed 99 characters
    scanf("%s", str);
    long long int sum = 0;
    
<<<<<<< HEAD
    for (int i = 0; str[i] != '\0'; i++) {
=======
    for (int i = 0; i < strlen(str); i++) {
>>>>>>> 98c87cb78a (data updated)
        sum += (str[i] - '0');
    }
    
    if (sum % 9 == 0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    
    return 0;
}

// <END-OF-CODE>
