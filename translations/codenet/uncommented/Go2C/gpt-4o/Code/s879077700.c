#include <stdio.h>
#include <string.h>

int main() {
    char a[100]; // Assuming the input string will not exceed 99 characters
    scanf("%s", a);
    char *ans = "Good";
    
    for (int i = 0; i < 3; i++) {
        if (a[i] == a[i + 1]) {
            ans = "Bad";
            break; // Exit the loop early if we find a match
        }
    }
    
    printf("%s\n", ans);
    return 0;
}

// <END-OF-CODE>
