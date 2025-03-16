
package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Declare a variable to hold user input
        int a;

        // Read an integer from standard input
        Scanner scanner = new Scanner(System.in);
        a = scanner.nextInt();

        // Call the walkOnMultiplicationTable function and print the result
        System.out.println(walkOnMultiplicationTable(a));
    }

    // walkOnMultiplicationTable calculates a specific value based on the input number.
    // It finds the largest divisor of the number that is less than the square root of the number.
    public static int walkOnMultiplicationTable(int num) {
        // Initialize a variable to store the largest divisor found
        int div = 0;

        // Iterate from the largest integer less than or equal to the square root of num down to 2
        for (int i = (int) Math.sqrt(num); i > 1; i--) {
            // Check if i is a divisor of num
            if (num % i == 0) {
                div = i; // Store the divisor
                break;   // Exit the loop once the largest divisor is found
            }
        }

        // If no divisor was found, return num - 1 (indicating num is prime)
        if (div == 0) {
            return num - 1;
        }

        // Calculate and return the result based on the found divisor
        return div + num / div - 2;
    }
}

