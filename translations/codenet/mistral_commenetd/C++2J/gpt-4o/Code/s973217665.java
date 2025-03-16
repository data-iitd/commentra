import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of test cases

        while (n-- > 0) { // Process each test case
            int p = scanner.nextInt(); // Read p from standard input
            int q = scanner.nextInt(); // Read q from standard input

            int l = (int) Math.sqrt(p * p + q * q); // Calculate the square root of p^2 + q^2

            boolean isPrime = true; // Initialize isPrime to true

            for (int i = 0; i < l; i++) { // Iterate through all possible integers i from 0 to l-1
                for (int j = 0; j < l; j++) { // Iterate through all possible integers j from 0 to l-1
                    int x = i * i + j * j; // Calculate x = i^2 + j^2

                    if (x <= 1) continue; // If x is less than or equal to 1, skip to the next iteration
                    if (x > p * p + q * q) continue; // If x is greater than p^2 + q^2, skip to the next iteration

                    if ((i * p + j * q) % x == 0 && (i * q - j * p) % x == 0) { // Check divisibility conditions
                        isPrime = false; // If so, set isPrime to false
                        break; // Exit the inner loop
                    }
                }
                if (!isPrime) break; // Exit the outer loop if isPrime is false
            }

            System.out.println(isPrime ? "P" : "C"); // Print "P" if isPrime is still true, otherwise print "C"
        }

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
