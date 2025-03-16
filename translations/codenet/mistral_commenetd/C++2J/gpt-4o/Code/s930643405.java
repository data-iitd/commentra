import java.util.Scanner;

public class Main {
    // Define a boolean array to keep track of digits that have been seen
    static boolean[] d = new boolean[10]; 
    static int n, k; // Input variables for the number and the number of digits to check

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read input
        n = scanner.nextInt();
        k = scanner.nextInt();

        // Check each digit in the input number 'k' times
        for (int i = 0; i < k; ++i) {
            int a = scanner.nextInt(); // Read the digit from the input
            d[a] = true; // Mark the digit as seen
        }

        // Keep generating numbers until a valid one is found
        while (true) {
            int x = n; // Initialize a variable 'x' to store the current number being checked
            boolean hantei = true; // A flag to indicate if the current number is valid

            // Check each digit in the number 'x'
            while (x > 0) {
                // If the current digit has already been seen, then the number is not valid
                if (d[x % 10]) {
                    hantei = false;
                    break;
                }
                x /= 10; // Move to the next digit
            }

            // If the current number is valid, print it and exit the loop
            if (hantei) {
                System.out.println(n);
                break;
            }

            // If the current number is not valid, increment 'n' and continue checking
            n++;
        }

        scanner.close();
    }
}
// <END-OF-CODE>
