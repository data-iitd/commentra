import java.util.*;
import static java.lang.System.*;

public class Main {
    public static void main(String[] $) {
        // Initialize a Scanner object to read input from the console
        Scanner sc = new Scanner(in);
        
        // Read the number of elements to be processed
        int n = sc.nextInt();
        
        // Initialize a counter for even numbers
        int d = 0;
        
        // Loop through each element
        for (int i = 0; i < n; i++) {
            // Increment the counter if the current element is even
            d += sc.nextInt() % 2;
        }
        
        // Output "YES" if the count of even numbers is even, otherwise output "NO"
        out.println(d % 2 == 0 ? "YES" : "NO");
    }
}
