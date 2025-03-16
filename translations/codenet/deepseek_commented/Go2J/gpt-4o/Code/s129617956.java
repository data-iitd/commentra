import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer n from the standard input
        int n = scanner.nextInt();
        
        // Calculate the square root of n and store it in rt
        int rt = (int) Math.sqrt(n);
        
        // Initialize minf to 100, which will hold the minimum number of digits
        int minf = 100;
        
        // Iterate from 1 to rt + 1 to find divisors of n
        for (int i = 1; i <= rt; i++) {
            if (n % i == 0) {
                // If i is a divisor of n, calculate the quotient b
                int b = n / i;
                
                // Count the number of digits in b
                int ndigit = 0;
                while (b > 0) {
                    b /= 10;
                    ndigit++;
                }
                
                // Update minf with the minimum number of digits found
                minf = Math.min(minf, ndigit);
            }
        }
        
        // Print the minimum number of digits
        System.out.println(minf);
        
        scanner.close();
    }
}

// <END-OF-CODE>
