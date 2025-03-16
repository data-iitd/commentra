#include<stdio.h>
#include<string.h>
#include<stdlib.h>

public class Main {
    public static void main(String[] args) {
        // Declare variables
        int n, i; // n: number of elements, i: loop index
        int h[100001]; // Array to store heights
        int max = -1; // Variable to track the maximum height
        int flag = 0; // Flag to indicate if the condition is met

        // Read the number of elements
        scanf("%d", &n);

        // Loop to read heights and determine the maximum height
        for(i = 0; i < n; i++) {
            // Read height into the array
            scanf("%d", &h[i]);
            
            // Update maximum height if current height is greater
            if(max < h[i]) max = h[i];

            // Check if the difference between max height and current height is 2 or more
            if(max - h[i] >= 2) flag = 1; // Set flag if condition is met
        }

        // Output result based on the flag value
        if(flag == 1) 
            printf("No\n"); // If flag is set, print "No"
        else 
            printf("Yes\n"); // If flag is not set, print "Yes"

        return 0; // Exit the program
    }
}

