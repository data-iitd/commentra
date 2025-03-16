#include <stdio.h>
#include <math.h>

int main() {
    int menu[5][2];  // Initialize an array to store menu items
    int ans = 0;  // Initialize a variable to accumulate the total cost

    // Loop to collect 5 menu items from user input
    for (int i = 0; i < 5; i++) {
        scanf("%d", &menu[i][0]);  // Take input from the user
        menu[i][1] = menu[i][0] % 10;  // Extract the last digit of the input and store it in the second element
        if (menu[i][1] == 0) {  // If the last digit is 0
            menu[i][1] = 10;  // Change it to 10 (to avoid zero as a value)
        }
    }

    // Sort the menu based on the second element (e) of each sublist
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (menu[i][1] > menu[j][1]) {  // If the first element of the ith sublist is greater than the first element of the jth sublist
                int temp[2];  // Initialize a temporary array to store the values of the ith and jth sublists
                temp[0] = menu[i][0];  // Store the first element of the ith sublist in the first element of the temporary array
                temp[1] = menu[i][1];  // Store the second element of the ith sublist in the second element of the temporary array
                menu[i][0] = menu[j][0];  // Store the first element of the jth sublist in the first element of the ith sublist
                menu[i][1] = menu[j][1];  // Store the second element of the jth sublist in the second element of the ith sublist
                menu[j][0] = temp[0];  // Store the first element of the temporary array in the first element of the jth sublist
                menu[j][1] = temp[1];  // Store the second element of the temporary array in the second element of the jth sublist
            }
        }
    }

    // Loop through the sorted menu starting from the second item
    for (int i = 1; i < 5; i++) {
        // Calculate the cost for each item, rounding up to the nearest multiple of 10
        ans += ceil(menu[i][0] / 10) * 10;
    }

    // Print the total cost, including the first item's original value
    printf("%d", ans + menu[0][0]);  // Add the first item's value to the accumulated cost and print the result

    return 0;
}

