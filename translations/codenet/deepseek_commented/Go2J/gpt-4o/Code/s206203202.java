import java.util.Scanner;

public class Main {
    
    // Abs returns the absolute value of an integer
    public static int abs(int x) {
        return (x < 0) ? -x : x;
    }

    // min returns the smaller of two integers
    public static int min(int a, int b) {
        return (a > b) ? b : a;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int N = scanner.nextInt(); // Read first integer
        int K = scanner.nextInt(); // Read second integer

        int x = N % K; // Calculate the remainder of N divided by K

        x = min(abs(x - K), x); // Calculate the minimum of the absolute difference and x itself
        System.out.println(x);   // Print the result
        
        scanner.close();
    }
}

// <END-OF-CODE>
