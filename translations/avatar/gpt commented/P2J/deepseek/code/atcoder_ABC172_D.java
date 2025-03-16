import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the integer N from input
        int N = scanner.nextInt();
        
        // Initialize the answer variable to accumulate the result
        long ans = 0;
        
        // Loop through each integer from 1 to N (inclusive)
        for (int i = 1; i <= N; i++) {
            // Calculate the contribution of the current integer i to the answer
            ans += i * (N / i) * (N / i + 1) / 2;
        }
        
        // Print the final result
        System.out.println(ans);
    }
}
