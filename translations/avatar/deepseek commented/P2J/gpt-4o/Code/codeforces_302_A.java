import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers n and m from input
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character
        
        // Read the next line and count the number of '-' characters
        String input = scanner.nextLine();
        int sa = (int) input.chars().filter(ch -> ch == '-').count();
        
        // Set sa to the minimum of n - sa and sa
        sa = Math.min(n - sa, sa);
        
        List<String> ss = new ArrayList<>();
        // Initialize an empty list to store results
        
        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            // Read two integers a and b in each iteration of the loop
            
            b -= a; // Subtract a from b
            
            // Check if b is odd and within certain bounds
            if (b % 2 == 1 && b <= sa * 2) {
                ss.add("1\n"); // Append "1\n" to ss if condition is met
            } else {
                ss.add("0\n"); // Append "0\n" to ss otherwise
            }
        }
        
        // Join and print the contents of ss
        System.out.print(String.join("", ss));
        
        scanner.close();
    }
}
// <END-OF-CODE>
