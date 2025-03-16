#include <stdio.h>
#include <string.h>
#include <math.h>

// Define a function calculate that takes two arguments: an integer n and a string s
void calculate(int n, char *s) {
    // Create a list arr from the string s
    char arr[1000];
    strcpy(arr, s);

    // Count the number of occurrences of each color in the list arr and store them in variables rNum, gNum, and bNum
    int rNum = 0, gNum = 0, bNum = 0;
    for (int i = 0; i < strlen(arr); i++) {
        if (arr[i] == 'R') {
            rNum++;
        } else if (arr[i] == 'G') {
            gNum++;
        } else if (arr[i] == 'B') {
            bNum++;
        }
    }

    // Initialize a variable sum to 0
    int sum = 0;

    // Use a for loop to iterate through each step from 1 to the ceiling of N/2
    for (int step = 1; step <= ceil(n/2); step++) {
        // Inside the inner for loop, join three consecutive elements of the list arr to form a string s
        char s[1000];
        int i = 0;
        for (int j = 0; j < 3; j++) {
            s[j] = arr[i];
            i++;
        }

        // Check if the string s is equal to any of the six possible color combinations: "RGB", "RBG", "BGR", "BRG", "GBR", or "GRB"
        if (strcmp(s, "RGB") == 0 || strcmp(s, "RBG") == 0 || strcmp(s, "BGR") == 0 || strcmp(s, "BRG") == 0 || strcmp(s, "GBR") == 0 || strcmp(s, "GRB") == 0) {
            sum++;
        }
    }

    // After the inner for loop, print the result of the calculation: rNum * gNum * bNum - sum
    printf("%d\n", rNum * gNum * bNum - sum);
}

// Call the calculate function with the input values N and S
int main() {
    int n;
    char s[1000];
    scanf("%d", &n);
    scanf("%s", s);
    calculate(n, s);
    return 0;
}

