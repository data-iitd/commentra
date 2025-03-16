

import java.util.Scanner;

public class atcoder_ABC142_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int t = 0;
        for (int i = 0; i < n; i++) {
            if ((i + 1) % 2!= 0) {
                t++;
            }
        }
        System.out.println((double) t / n);
    }
}

// Read the value of n from input
// Initialize a counter to keep track of odd numbers
// Loop through each number from 0 to n-1
// Check if the current index plus one is odd
// Increment the counter if the condition is true
// Calculate the ratio of odd numbers to the total numbers and print it
