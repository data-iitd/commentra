#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[1000]; // Step 1: The program starts by taking a string input from the user.
    printf("Enter a string: ");
    scanf("%s", s);

    int count = 0; // Step 2: It initializes a counter to keep track of the lengths of consecutive valid characters.
    int counter[1000] = {0}; // Step 4: It splits the input string into individual characters.
    int li[1000];
    int li_index = 0;

    if (strlen(s) == 0) { // Step 3: It checks if the input string is empty and returns immediately if it is.
        return 0;
    }

    for (int i = 0; i < strlen(s); i++) { // Step 5: It iterates through each character in the split string, incrementing the count for valid characters and resetting the count for invalid characters.
        if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T') {
            count++;
        } else {
            li[li_index++] = count;
            count = 0;
        }
    }

    li[li_index++] = count; // Step 6: It appends the final count to the counter array and sorts the array.

    for (int i = 0; i < li_index; i++) {
        for (int j = i + 1; j < li_index; j++) {
            if (li[i] < li[j]) {
                int temp = li[i];
                li[i] = li[j];
                li[j] = temp;
            }
        }
    }

    printf("%d\n", li[0]); // Step 7: Finally, it prints the maximum value in the sorted counter array.
    return 0;
}
