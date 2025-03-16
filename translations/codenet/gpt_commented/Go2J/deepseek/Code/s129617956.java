import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine());
        
        // Calculate the integer square root of n
        int rt = (int) Math.sqrt(n);
        
        // Initialize a variable to keep track of the minimum number of digits found
        int minf = 100;
        
        // Loop through all integers from 1 to the square root of n
        for (int i = 1; i < rt + 1; i++) {
            // Check if i is a divisor of n
            if (n % i == 0) {
                // Calculate the corresponding divisor b
                int b = n / i;
                
                // Initialize a counter for the number of digits in b
                int ndigit = 0;
                
                // Count the number of digits in b
                while (b > 0) {
                    b /= 10;
                    ndigit++;
                }
                
                // Update minf with the minimum number of digits found
                minf = Math.min(minf, ndigit);
            }
        }
        
        // Print the minimum number of digits found among the divisors
        System.out.println(minf);
    }
}
