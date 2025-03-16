#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int value;
    int last_digit;
} MenuItem;

int compare(const void *a, const void *b) {
    MenuItem *item1 = (MenuItem *)a;
    MenuItem *item2 = (MenuItem *)b;
    return item1->last_digit - item2->last_digit;
}

int main() {
    MenuItem menu[5];
    for (int i = 0; i < 5; i++) {
        char input[20];
        scanf("%s", input); // Taking input from the user
        int value = atoi(input); // Converting the input string to an integer
        int last_digit = value % 10; // Extracting the last digit
        if (last_digit == 0) {
            last_digit = 10; // If the last digit is 0, change it to 10
        }
        menu[i].value = value;
        menu[i].last_digit = last_digit; // Storing the value and the processed last digit
    }

    qsort(menu, 5, sizeof(MenuItem), compare); // Sorting the menu array based on the last digit

    int ans = 0;
    for (int i = 1; i < 5; i++) {
        ans += ceil((double)menu[i].value / 10) * 10; // Calculating the sum
    }
    printf("%d\n", ans + menu[0].value); // Printing the sum of the first element and the calculated ans

    return 0;
}

// <END-OF-CODE>
