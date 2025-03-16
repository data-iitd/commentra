#include <stdio.h>
<<<<<<< HEAD
#include <string.h>

int main() {
    char str[100]; // Assuming a maximum length of 100 for the input string
=======

int main() {
    char str[100]; // Assuming the input string will not exceed 99 characters
>>>>>>> 98c87cb78a (data updated)
    scanf("%s", str);
    
    if (str[2] == str[3] && str[4] == str[5]) 
        printf("Yes\n");
    else 
        printf("No\n");
    
    return 0;
}

// <END-OF-CODE>
