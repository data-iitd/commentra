
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public final class Main {
    private Main() {
        // Private constructor to prevent instantiation of the class
    }

    public static int solveCRT(List<Integer> remainders, List<Integer> moduli) {
        // Function to solve the Chinese Remainder Theorem problem
        int product = 1; // Initialize product to 1
        int result = 0; // Initialize result to 0

        for (int mod : moduli) {
            // Multiply all moduli to get the product
            product *= mod;
        }

        for (int i = 0; i < moduli.size(); i++) {
            // Calculate the partial product and inverse for each modulus
            int partialProduct = product / moduli.get(i);
            int inverse = modInverse(partialProduct, moduli.get(i));

            // Update the result by adding the product of the remainders, partial product and inverse
            result += remainders.get(i) * partialProduct * inverse;
        }

        // Calculate the final result by taking the remainder of the result with the product
        result = result % product;

        // If the result is negative, add the product to make it positive
        if (result < 0) {
            result += product;
        }

        // Return the final result
        return result;
    }

    private static int modInverse(int a, int m) {
        // Function to calculate the modular inverse of 'a' with respect to 'm'
        int m0 = m; // Save the original value of 'm'
        int x0 = 0; // Initialize 'x0' to 0
        int x1 = 1; // Initialize 'x1' to 1

        if (m == 1) {
            // If 'm' is 1, return 0 as the modular inverse of any number is 0
            return 0;
        }

        while (a > 1) {
            // Calculate the quotient and update 'a' and 'm'
            int q = a / m;
            int t = m;
            m = a % m;
            a = t;
            t = x0;
            x0 = x1 - q * x0;
            x1 = t;
        }

        // If 'x1' is negative, add the original value of 'm' to make it positive
        if (x1 < 0) {
            x1 += m0;
        }

        // Return the modular inverse
        return x1;
    }

    public static void main(String[] args) {
        // Main function to read input and call the solveCRT function
        Scanner scanner = new Scanner(System.in); // Initialize the scanner to read input from the console

        int n = scanner.nextInt(); // Read the number of pairs (remainder, modulus)

        List<Integer> remainders = new ArrayList<>(); // Initialize an empty list to store remainders
        List<Integer> moduli = new ArrayList<>(); // Initialize an empty list to store moduli

        for (int i = 0; i < n; i++) {
            // Read each pair (remainder, modulus) and add them to the respective lists
            int remainder = scanner.nextInt();
            int modulus = scanner.nextInt();
            remainders.add(remainder);
            moduli.add(modulus);
        }

        int solution = solveCRT(remainders, moduli); // Call the solveCRT function to find the solution

        System.out.println("Smallest positive solution: " + solution); // Print the solution to the console

        scanner.close(); // Close the scanner to free up resources
    }
}