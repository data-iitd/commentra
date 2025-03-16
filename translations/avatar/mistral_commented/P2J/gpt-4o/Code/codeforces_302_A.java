import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Define the number of strings n and the number of operations m
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Calculate the number of '-' symbols in the input string
        String inputString = scanner.next();
        int sa = (int) inputString.chars().filter(ch -> ch == '-').count();
        
        // Ensure the number of '-' symbols is valid
        sa = Math.min(n - sa, sa);
        
        // Initialize a list to store the results of each operation
        List<String> ss = new ArrayList<>();
        
        // Perform each operation as described in the problem statement
        for (int i = 0; i < m; i++) {
            // Read two integers a and b from the input
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            
            // Calculate the difference between b and a
            b -= a;
            
            // Check if the difference is valid based on the number of '-' symbols
            if (b % 2 == 0 || b > (sa << 1)) {
                // If the difference is valid, add '1' to the result list
                ss.add("1\n");
            } else {
                // If the difference is not valid, add '0' to the result list
                ss.add("0\n");
            }
        }
        
        // Print the final result by joining all the strings in the list
        System.out.print(String.join("", ss));
        
        scanner.close();
    }
}
// <END-OF-CODE>
