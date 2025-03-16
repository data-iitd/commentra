

import java.util.Scanner;

public class s363337466{

    // Function to check if a number is prime
    public static int walkOnMultiplicationTable(int num) {

        // Initialize divisor variable
        int div = 0;

        // Check divisibility of the number with the square root of the number
        for (int i = (int) Math.sqrt(num); i > 1; i--) {
            // Check if the number is divisible by the current number
            if (num % i == 0) {
                // If yes, then the current number is divisor
                div = i;
                // Break the loop as we have found the divisor
                break;
            }
        }

        // If the number is not divisible by any number till the square root, then it is a prime number
        if (div == 0) {
            // Return the number - 1 as 0 is not considered as a prime number
            return num - 1;
        }

        // If the number is divisible by some number, then it is not a prime number
        // Return the divisor + number/divisor - 2 as the prime number
        return div + num / div - 2;

    }

    // s363337466 function to read the number and print the prime number
    public static void main(String[] args) {
        // Initialize a variable to read the number
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();

        // Print the prime number using the walkOnMultiplicationTable function
        System.out.println(walkOnMultiplicationTable(a));
    }

}

// 