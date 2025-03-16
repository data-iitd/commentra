
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 1000

typedef struct {
    int count;
    char value;
} Counter;

void sort_counter(Counter *counter, int length) {
    // Define the sort_counter function that takes two arguments, counter and length
    int i, j;
    Counter temp;
    for (i = 0; i < length - 1; i++) {
        // Loop through the counter array
        for (j = i + 1; j < length; j++) {
            // Loop through the counter array
            if (counter[i].count > counter[j].count) {
                // If the current element is greater than the next element
                temp = counter[i];
                counter[i] = counter[j];
                counter[j] = temp;
            }
        }
    }
}

bool is_equal(Counter *counter1, Counter *counter2, int length) {
    // Define the is_equal function that takes three arguments, counter1, counter2, and length
    int i;
    for (i = 0; i < length; i++) {
        // Loop through the counter arrays
        if (counter1[i].count != counter2[i].count) {
            // If the current element is not equal
            return false;
        }
    }
    return true;
}

int main() {
    // Define the main function to get input and print the result
    char s[MAX_LENGTH];
    // Define an array of characters for s
    char t[MAX_LENGTH];
    // Define an array of characters for t
    int i, j, k;
    // Define integers for loop counters
    Counter *counter1;
    // Define a pointer to a Counter object for counter1
    Counter *counter2;
    // Define a pointer to a Counter object for counter2
    scanf("%s", s);
    // Get input for s from the user
    scanf("%s", t);
    // Get input for t from the user
    counter1 = (Counter *)malloc(sizeof(Counter) * MAX_LENGTH);
    // Allocate memory for counter1
    counter2 = (Counter *)malloc(sizeof(Counter) * MAX_LENGTH);
    // Allocate memory for counter2
    for (i = 0, j = 0, k = 0; s[i] != '\0'; i++) {
        // Loop through the characters of s
        if (s[i] != ' ') {
            // If the current character is not a space
            counter1[j].count = 1;
            // Set the count of the current element to 1
            counter1[j].value = s[i];
            // Set the value of the current element to the current character
            j++;
        }
    }
    for (i = 0, j = 0, k = 0; t[i] != '\0'; i++) {
        // Loop through the characters of t
        if (t[i] != ' ') {
            // If the current character is not a space
            counter2[j].count = 1;
            // Set the count of the current element to 1
            counter2[j].value = t[i];
            // Set the value of the current element to the current character
            j++;
        }
    }
    sort_counter(counter1, j);
    // Call the sort_counter function with counter1 and j as arguments
    sort_counter(counter2, j);
    // Call the sort_counter function with counter2 and j as arguments
    if (is_equal(counter1, counter2, j)) {
        // If the sorted values of s and t are equal
        printf("Yes\n");
    } else {
        // If not equal
        printf("No\n");
    }
    // Print the result
    free(counter1);
    // Free the memory allocated for counter1
    free(counter2);
    // Free the memory allocated for counter2
    return 0;
}

