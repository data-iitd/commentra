#include <stdio.h>
#include <string.h>

void print(const char* str) {
    printf("%s\n", str);
}

int main() {
    char S[100]; // Assuming the input string will not exceed 99 characters
    scanf("%s", S);
    
    if (strcmp(S, "Sunny") == 0) {
        print("Cloudy");
    } else if (strcmp(S, "Cloudy") == 0) {
        print("Rainy");
    } else {
        print("Sunny");
    }
    
    return 0;
}

// <END-OF-CODE>
