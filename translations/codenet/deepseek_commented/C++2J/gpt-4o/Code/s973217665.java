import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of test cases
        while (n-- > 0) {
            int p = scanner.nextInt();
            int q = scanner.nextInt(); // Read the values of p and q for each test case
            int l = (int) Math.sqrt(p * p + q * q); // Calculate the length of the hypotenuse
            boolean isPrime = true; // Initialize a flag to check if the number is prime
            
            for (int i = 0; i < l; i++) { // Loop through all pairs (i, j) within the range of l
                for (int j = 0; j < l; j++) {
                    int x = i * i + j * j; // Calculate the sum of squares
                    if (x <= 1 || x >= p * p + q * q) continue; // Skip if x is out of range
                    if ((i * p + j * q) % x == 0 && (i * q - j * p) % x == 0) {
                        isPrime = false; // Check the conditions
                    }
                }
            }
            System.out.println(isPrime ? "P" : "C"); // Print the result
        }
        scanner.close();
    }
}
// <END-OF-CODE>
