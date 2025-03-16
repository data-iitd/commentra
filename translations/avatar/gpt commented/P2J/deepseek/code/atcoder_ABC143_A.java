import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers A and B from user input, separated by a space
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        
        // Calculate the result by subtracting twice the value of B from A
        int ans = A - 2 * B;
        
        // If the result is negative, set it to zero
        if (ans < 0) {
            ans = 0;
        }
        
        // Print the final result
        System.out.println(ans);
        
        scanner.close();
    }
}
