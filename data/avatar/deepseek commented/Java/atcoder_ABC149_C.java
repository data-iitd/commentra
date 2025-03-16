import java.util.Scanner; // Importing the Scanner class for input
import java.lang.Math; // Importing the Math class for mathematical operations

public class Main {
    public static void main(String[] args) {
        Scanner stdIn = new Scanner(System.in); // Creating a Scanner object to read input
        int x = Integer.parseInt(stdIn.next()); // Reading an integer input from the user and parsing it

        // Step 2: Check if the input is not equal to 2 and is even. If so, increment the input by 1.
        if (x != 2 && x % 2 == 0) {
            x++;
        }

        // Step 3: Enter a loop where it checks if the number is a prime number.
        while (true) {
            int i;
            double sqrtNum = Math.sqrt(x); // Calculate the square root of the number

            // Step 4: Check for factors from 3 up to the square root of the number, incrementing by 2 (only odd numbers)
            for (i = 3; i <= sqrtNum; i += 2) {
                if (x % i == 0) {
                    break; // If a factor is found, break out of the loop
                }
            }

            // Step 5: If no factors are found and i is greater than the square root, the number is prime
            if (i > sqrtNum) {
                break; // Exit the loop once a prime number is found
            }

            // If the number is not prime, increment by 2 and check again
            x += 2;
        }

        // Step 5: Print the prime number found
        System.out.println(x);
    }
}
