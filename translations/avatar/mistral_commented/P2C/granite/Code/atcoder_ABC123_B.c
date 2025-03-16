
#include <stdio.h>
#include <math.h>

int main() {
    // Initialize an empty array called menu
    int menu[5][2];
    
    // Use a for loop to iterate 5 times
    for (int i = 0; i < 5; i++) {
        // Take user input and assign it to the variable m
        char m[10];
        scanf("%s", m);
        
        // Extract the last character of the string m to determine the exponent e
        int e = m[strlen(m) - 1] - '0';
        
        // If e is 0, set it to 10
        if (e == 0) {
            e = 10;
        }
        
        // Assign the integer value of m to the first element of the current subarray in the menu array
        menu[i][0] = atoi(m);
        
        // Assign the exponent e to the second element of the current subarray in the menu array
        menu[i][1] = e;
    }
    
    // Sort the menu array based on the exponent value using the qsort() function
    qsort(menu, 5, sizeof(menu[0]), compare);
    
    // Initialize a variable called ans to 0
    int ans = 0;
    
    // Use a for loop to iterate through the menu array starting from the second element (index 1)
    for (int i = 1; i < 5; i++) {
        // Calculate the number of full 10s that can be obtained by dividing the integer value by 10 and rounding up using the ceil() function from the math.h library
        int num_full_10s = ceil(menu[i][0] / 10.0);
        
        // Multiply this value by 10 and add it to the ans variable
        ans += num_full_10s * 10;
    }
    
    // Finally, print the sum of the first element in the menu array (which is the initial number) and the value of ans
    printf("%d\n", menu[0][0] + ans);
    
    return 0;
}

// Define a comparison function for qsort() to sort the menu array based on the exponent value
int compare(const void *a, const void *b) {
    return ((int *)a)[1] - ((int *)b)[1];
}

