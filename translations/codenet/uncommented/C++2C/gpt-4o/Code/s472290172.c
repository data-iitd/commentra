#include <stdio.h>
<<<<<<< HEAD
#include <string.h>
=======
>>>>>>> 98c87cb78a (data updated)

int main() {
    char str[100]; // Assuming the input string will not exceed 99 characters
    scanf("%s", str);
    
    int max = 0, cnt = 0;
<<<<<<< HEAD
    for (int i = 0; i < strlen(str); i++) {
=======
    for (int i = 0; str[i] != '\0'; i++) {
>>>>>>> 98c87cb78a (data updated)
        char sc = str[i];
        if (sc == 'A' || sc == 'C' || sc == 'G' || sc == 'T') {
            cnt++;
        } else {
            cnt = 0;
        }
        max = (max < cnt) ? cnt : max;
    }
    
    printf("%d\n", max);
    return 0;
<<<<<<< HEAD
} // <END-OF-CODE>
=======
}

// <END-OF-CODE>
>>>>>>> 98c87cb78a (data updated)
