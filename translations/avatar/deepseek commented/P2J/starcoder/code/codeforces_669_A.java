
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();  // Take an integer input from the user
        System.out.println(fibonacci(n));  // Print the nth Fibonacci number
    }

    public static int fibonacci(int n) {
        if (n <= 0) {  // Return 0 for non-positive input
            return 0;
        } else if (n == 1) {  // Return 1 for input of 1
            return 1;
        } else {
            int a = 0, b = 1;  // Initialize the first two Fibonacci numbers
            for (int i = 2; i <= n; i++) {  // Loop from 2 to n
                int c = a + b;  // Update the values of a and b
                a = b;
                b = c;
            }
            return b;  // Return the nth Fibonacci number
        }
    }
}

