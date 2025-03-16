import java.util.Scanner;

public class Main {
    // Abs returns the absolute value of an integer
    public static int Abs(int x) {
        if (x < 0) {
            return -x;
        }
        return x;
    }

    // min returns the smaller of two integers
    public static int min(int a, int b) {
        if (a > b) {
            return b;
        }
        return a;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt(); // Read first integer from input
        int K = scanner.nextInt(); // Read second integer from input

        int x = N % K; // Calculate the remainder of N divided by K

        x = min(Abs(x - K), x); // Calculate the minimum of the absolute difference and x itself
        System.out.println(x); // Print the result
    }
}
