#include <stdio.h>
#include <string.h>

int main() {
    int n; // Declaring an integer variable to store the number of inputs
    char s[100]; // Declaring a string variable to store the input string
    scanf("%d %s", &n, s); // Reading input from the user and storing it in n and s
    printf("%d\n", strstr(s, "ABC") - s + 1); // Counting the occurrences of "ABC" in s and printing the result
    return 0;
}
