import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer from standard input
        int n = scanner.nextInt();
        int rt = (int) Math.sqrt(n); // Calculate the square root of n

        // Initialize minimum factor with a large value
        int minf = 100;

        // Check divisibility for numbers from 1 to the square root of n
        for (int i = 1; i <= rt; i++) {
            // Check if n is divisible by i
            if (n % i == 0) {
                // Calculate the number of digits in the divisor
                int b = n / i;
                int ndigit = 0;
                while (b > 0) {
                    b /= 10;
                    ndigit++;
                }
                // Update minimum factor if a divisor with fewer digits is found
                minf = Math.min(minf, ndigit);
            }
        }

        // Print the result
        System.out.println(minf);
    }
}

// <END-OF-CODE>
