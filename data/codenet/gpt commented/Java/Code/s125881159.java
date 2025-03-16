import java.util.*;
import static java.lang.System.*;

public class Main {
    public static void main(String[] $) {
        // Create a Scanner object to read input from the standard input stream
        Scanner sc = new Scanner(in);
        
        // Read the number of integers to be processed
        int n = sc.nextInt();
        
        // Initialize a variable to count the number of odd integers
        int d = 0;
        
        // Loop through the number of integers specified
        for (int i = 0; i < n; i++) {
            // Read the next integer, check if it is odd (using modulus), and increment the count if it is
            d += sc.nextInt() % 2;
        }
        
        // Output "YES" if the count of odd integers is even, otherwise output "NO"
        out.println(d % 2 == 0 ? "YES" : "NO");
    }
}
