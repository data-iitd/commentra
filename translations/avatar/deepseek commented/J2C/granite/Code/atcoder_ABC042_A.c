

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a variable to store the input line
    char line[100];
    
    // Read a line of input from the user
    fgets(line, sizeof(line), stdin);
    
    // Split the input line into an array of strings
    char *list[3];
    int i = 0;
    char *token = strtok(line, " ");
    while (token!= NULL) {
        list[i] = token;
        token = strtok(NULL, " ");
        i++;
    }
    
    // Parse the first three elements of the array as integers
    int x = atoi(list[0]);
    int a = atoi(list[1]);
    int y = atoi(list[2]);
    
    // Initialize a variable to store the result
    char h[] = "NO";
    
    // Check if any of the integers is either 5 or 7
    if (x == 5 || x == 7 || a == 5 || a == 7 || y == 5 || y == 7) {
        // Check if the sum of the integers is 17
        if (x + y + a == 17) {
            h[0] = 'Y';
            h[1] = 'E';
            h[2] = 'S';
        }
    }
    
    // Print the result
    printf("%s\n", h);
    
    return 0;
}
