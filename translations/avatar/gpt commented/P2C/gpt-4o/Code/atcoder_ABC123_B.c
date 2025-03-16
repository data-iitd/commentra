#include <stdio.h>
#include <stdlib.h>  // For malloc and free
#include <math.h>    // For ceil

#define MENU_SIZE 5

typedef struct {
    int value;
    int e;
} MenuItem;

int compare(const void *a, const void *b) {
    MenuItem *itemA = (MenuItem *)a;
    MenuItem *itemB = (MenuItem *)b;
    return itemA->e - itemB->e;  // Sort by the second element (e)
}

int main() {
    MenuItem *menu = malloc(MENU_SIZE * sizeof(MenuItem));  // Allocate memory for menu items

    // Loop to collect 5 menu items from user input
    for (int i = 0; i < MENU_SIZE; i++) {
        char input[100];  // Buffer to hold user input
        scanf("%s", input);  // Take input from the user
        menu[i].value = atoi(input);  // Convert the input string to an integer
        int last_digit = menu[i].value % 10;  // Get the last digit
        menu[i].e = (last_digit == 0) ? 10 : last_digit;  // Set e to 10 if last digit is 0
    }

    // Sort the menu based on the second element (e)
    qsort(menu, MENU_SIZE, sizeof(MenuItem), compare);

    int ans = 0;  // Initialize a variable to accumulate the total cost

    // Loop through the sorted menu starting from the second item
    for (int i = 1; i < MENU_SIZE; i++) {
        // Calculate the cost for each item, rounding up to the nearest multiple of 10
        ans += (int)ceil(menu[i].value / 10.0) * 10;
    }

    // Print the total cost, including the first item's original value
    printf("%d\n", ans + menu[0].value);  // Add the first item's value to the accumulated cost

    free(menu);  // Free the allocated memory
    return 0;
}

// <END-OF-CODE>
