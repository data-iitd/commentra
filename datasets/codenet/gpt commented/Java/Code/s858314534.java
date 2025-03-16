import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        @SuppressWarnings("resource")
        Scanner scanner = new Scanner(System.in);

        // Read the first integer input (A)
        int A = scanner.nextInt();

        // Read the second integer input (B)
        int B = scanner.nextInt();

        // Read the third integer input (T)
        int T = scanner.nextInt();

        // Calculate the result of (T / A) * B and log the output
        log((T / A) * B);
    }

    // Overloaded method to log a string message to the console
    private static void log(String str) {
        System.out.println(str);
    }

    // Overloaded method to log an integer value to the console
    private static void log(int str) {
        System.out.println(str);
    }
}
