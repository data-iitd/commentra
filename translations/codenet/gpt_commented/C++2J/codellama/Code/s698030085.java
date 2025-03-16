import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare two long long integer variables to hold the input values
        long a, b;

        // Read two integers from the standard input
        Scanner sc = new Scanner(System.in);
        a = sc.nextLong();
        b = sc.nextLong();

        // Check if the sum of a and b is even
        if ((a + b) % 2 == 0) {
            // If the sum is even, calculate and output the average
            System.out.println((a + b) / 2);
        } else {
            // If the sum is odd, output "IMPOSSIBLE"
            System.out.println("IMPOSSIBLE");
        }
    }
}

