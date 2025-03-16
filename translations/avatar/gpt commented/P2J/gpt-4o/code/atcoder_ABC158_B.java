import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object for input
        Scanner scanner = new Scanner(System.in);
        
        // Define the modulo constant
        final int MOD = 1000000007;
        
        // Read input values: N (total items), A (items of type A), B (items of type B)
        int N = scanner.nextInt();
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        
        // Initialize the answer variable
        long ans = 0;
        
        // Calculate how many complete cycles of (A + B) fit into N
        int rep = N / (A + B);
        
        // Add the total items of type A from the complete cycles to the answer
        ans += rep * A;
        
        // Calculate the remaining items after complete cycles
        int res = N - rep * (A + B);
        
        // Add the minimum of remaining items or A to the answer
        ans += Math.min(res, A);
        
        // Print the final answer
        System.out.println(ans);
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
