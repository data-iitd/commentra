#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_MENU_ITEMS 5

int main() {
    int menu[MAX_MENU_ITEMS][2];
    char m[10];
    int e;

    // Loop to collect 5 menu items from user input
    for (int i = 0; i < MAX_MENU_ITEMS; i++) {
        scanf("%s", m);
        e = m[strlen(m) - 1] - '0';  // Extract the last character of the input and convert it to an integer
        if (e == 0) {  // If the last digit is 0
            e = 10;  // Change it to 10 (to avoid zero as a value)
        }
        menu[i][0] = atoi(m);  // Convert the input string to an integer
        menu[i][1] = e;  // Store the last digit as e
    }

    // Sort the menu based on the second element (e) of each sublist
    for (int i = 0; i < MAX_MENU_ITEMS - 1; i++) {
        for (int j = 0; j < MAX_MENU_ITEMS - 1 - i; j++) {
            if (menu[j][1] > menu[j + 1][1]) {
                // Swap the elements
                int temp0 = menu[j][0];
                int temp1 = menu[j][1];
                menu[j][0] = menu[j + 1][0];
                menu[j][1] = menu[j + 1][1];
                menu[j + 1][0] = temp0;
                menu[j + 1][1] = temp1;
            }
        }
    }

    int ans = 0;

    // Loop through the sorted menu starting from the second item
    for (int i = 1; i < MAX_MENU_ITEMS; i++) {
        // Calculate the cost for each item, rounding up to the nearest multiple of 10
        ans += (int)ceil((double)menu[i][0] / 10) * 10;
    }

    // Print the total cost, including the first item's original value
    printf("%d\n", ans + menu[0][0]);

    return 0;
}
