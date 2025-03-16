import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation of the utility class
    private Main() {
    }

    // Method to solve the Chinese Remainder Theorem (CRT)
    public static int solveCRT(List<Integer> remainders, List<Integer> moduli) {
        int product = 1; // Variable to store the product of all moduli
        int result = 0;  // Variable to accumulate the result

        // Calculate the product of all moduli
        for (int mod : moduli) {
            product *= mod;
        }

        // Calculate the result using the CRT formula
        for (int i = 0; i < moduli.size(); i++) {
            int partialProduct = product / moduli.get(i); // Calculate the partial product
            int inverse = modInverse(partialProduct, moduli.get(i)); // Find the modular inverse
            result += remainders.get(i) * partialProduct * inverse; // Update the result
        }

        // Apply modulo to ensure the result is within the range of the product
        result = result % product;
        if (result < 0) {
            result += product; // Adjust result if it's negative
        }
        return result; // Return the final result
    }

    // Method to compute the modular inverse using the Extended Euclidean Algorithm
    private static int modInverse(int a, int m) {
        int m0 = m; // Store the original modulus
        int x0 = 0; // Initialize x0
        int x1 = 1; // Initialize x1

        // If m is 1, the inverse is 0
        if (m == 1) {
            return 0;
        }

        // Apply the Extended Euclidean Algorithm
        while (a > 1) {
            int q = a / m; // Calculate quotient
            int t = m; // Store current modulus
            m = a % m; // Update modulus
            a = t; // Update a
            t = x0; // Store current x0
            x0 = x1 - q * x0; // Update x0
            x1 = t; // Update x1
        }

        // Ensure x1 is positive
        if (x1 < 0) {
            x1 += m0;
        }
        return x1; // Return the modular inverse
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for input
        int n = scanner.nextInt(); // Read the number of equations
        List<Integer> remainders = new ArrayList<>(); // List to store remainders
        List<Integer> moduli = new ArrayList<>(); // List to store moduli

        // Read each remainder and modulus pair
        for (int i = 0; i < n; i++) {
            int remainder = scanner.nextInt(); // Read remainder
            int modulus = scanner.nextInt(); // Read modulus
            remainders.add(remainder); // Add remainder to the list
            moduli.add(modulus); // Add modulus to the list
        }

        // Solve the CRT and print the smallest positive solution
        int solution = solveCRT(remainders, moduli);
        System.out.println("Smallest positive solution: " + solution);
        scanner.close(); // Close the scanner
    }
}
