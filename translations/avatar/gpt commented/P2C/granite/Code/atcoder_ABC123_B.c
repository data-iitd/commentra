
#include <stdio.h>  // Include the standard input/output library
#include <math.h>  // Include the math library for mathematical functions

int main() {
    int menu[5][2], i, j;  // Declare a 2D array to store menu items
    int ans = 0;  // Initialize a variable to accumulate the total cost

    // Loop to collect 5 menu items from user input
    for (i = 0; i < 5; i++) {
        char m[10];  // Declare a character array to store user input
        scanf("%s", m);  // Take input from the user
        menu[i][0] = atoi(m);  // Convert the input string to an integer and store it in menu[i][0]
        menu[i][1] = m[strlen(m) - 1] - '0';  // Extract the last character of the input and convert it to an integer
        if (menu[i][1] == 0) {  // If the last digit is 0
            menu[i][1] = 10;  // Change it to 10 (to avoid zero as a value)
        }
    }

    // Sort the menu based on the second element (e) of each sublist
    for (i = 0; i < 5; i++) {
        for (j = i + 1; j < 5; j++) {
            if (menu[j][1] < menu[i][1]) {  // Swap the elements if the second element is smaller
                int temp = menu[i][0];
                menu[i][0] = menu[j][0];
                menu[j][0] = temp;
                temp = menu[i][1];
                menu[i][1] = menu[j][1];
                menu[j][1] = temp;
            }
        }
    }

    // Loop through the sorted menu starting from the second item
    for (i = 1; i < 5; i++) {
        // Calculate the cost for each item, rounding up to the nearest multiple of 10
        ans += (menu[i][0] + 9) / 10 * 10;
    }

    // Print the total cost, including the first item's original value
    printf("%d\n", ans + menu[0][0]);  // Add the first item's value to the accumulated cost and print the result

    return 0;  // Return 0 to indicate successful execution
}
