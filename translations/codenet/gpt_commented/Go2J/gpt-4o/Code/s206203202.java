import java.util.Scanner;

public class Main {
    
    // Abs function returns the absolute value of an integer x.
    public static int abs(int x) {
        if (x < 0) {
            return -x; // If x is negative, return its negation.
        }
        return x; // If x is non-negative, return x itself.
    }

    // min function returns the smaller of two integers a and b.
    public static int min(int a, int b) {
        if (a > b) {
            return b; // If a is greater than b, return b.
        }
        return a; // Otherwise, return a.
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers N and K from standard input.
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        
        // Calculate the remainder of N divided by K.
        int x = N % K;
        // Determine the minimum between the absolute difference of (x - K) and x.
        x = min(abs(x - K), x);
        // Print the final result.
        System.out.println(x);
        
        scanner.close();
    }
}

// <END-OF-CODE>
