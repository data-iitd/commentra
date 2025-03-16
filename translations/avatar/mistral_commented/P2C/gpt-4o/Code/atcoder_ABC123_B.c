#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MENU_SIZE 5

// Structure to hold the integer value and exponent
typedef struct {
    int value;
    int exponent;
} MenuItem;

// Function to compare two MenuItem structures based on their exponent
int compare(const void *a, const void *b) {
    MenuItem *item1 = (MenuItem *)a;
    MenuItem *item2 = (MenuItem *)b;
    return item1->exponent - item2->exponent;
}

int main() {
    // Initialize an array of MenuItem structures
    MenuItem menu[MENU_SIZE];

    // Use a for loop to iterate 5 times
    for (int i = 0; i < MENU_SIZE; i++) {
        char m[100]; // Buffer to hold user input
        scanf("%s", m); // Take user input
        
        // Extract the last character of the string m to determine the exponent e
        int e = m[strlen(m) - 1] - '0'; // Convert last character to integer
        
        // If e is 0, set it to 10
        if (e == 0) {
            e = 10;
        }
        
        // Append the integer value and the exponent to the menu array
        menu[i].value = atoi(m); // Convert string to integer
        menu[i].exponent = e;
    }

    // Sort the menu array based on the exponent value
    qsort(menu, MENU_SIZE, sizeof(MenuItem), compare);

    // Initialize a variable called ans to 0
    int ans = 0;

    // Use a for loop to iterate through the menu array starting from the second element (index 1)
    for (int i = 1; i < MENU_SIZE; i++) {
        // Calculate the number of full 10s that can be obtained by dividing the integer value by 10 and rounding up
        int num_full_10s = (int)ceil((double)menu[i].value / 10);
        
        // Multiply this value by 10 and add it to the ans variable
        ans += num_full_10s * 10;
    }

    // Finally, print the sum of the first element in the menu array and the value of ans
    printf("%d\n", menu[0].value + ans);

    return 0;
}

// <END-OF-CODE>
