import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare integer variables to store input values
        int h1, m1, h2, m2, k;
        
        // Create a Scanner object to read input values
        Scanner scanner = new Scanner(System.in);
        
        // Read input values for h1, m1, h2, m2, and k from the standard input
        h1 = scanner.nextInt();
        m1 = scanner.nextInt();
        h2 = scanner.nextInt();
        m2 = scanner.nextInt();
        k = scanner.nextInt();
        
        // Calculate the difference in minutes between h2:m2 and h1:m1
        int ans = (h2 * 60 + m2) - (h1 * 60 + m1);
        
        // Print the result of subtracting k from the calculated difference
        System.out.println(ans - k);
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
