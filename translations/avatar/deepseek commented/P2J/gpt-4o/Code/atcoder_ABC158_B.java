import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Modulo value
        long mod = 1000000007;  
        
        // Reading N, A, and B
        int N = scanner.nextInt();
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        
        long ans = 0;  // Initializing the result variable
        
        // Calculating the number of complete cycles of A + B within N
        int rep = N / (A + B);
        
        // Updating the result with the number of complete cycles multiplied by A
        ans += rep * A;
        
        // Calculating the remaining days after the complete cycles
        int res = N - rep * (A + B);
        
        // Updating the result with the minimum of the remaining days and A
        ans += Math.min(res, A);
        
        // Printing the final result
        System.out.println(ans);
        
        scanner.close();
    }
}

// <END-OF-CODE>
