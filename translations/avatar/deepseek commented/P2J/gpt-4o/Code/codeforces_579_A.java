import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Take an integer input from the user
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        // Initialize a variable x to 1
        int x = 1;
        // Continue looping until the base-2 logarithm of n is an integer
        while (Math.log(n) / Math.log(2) % 1 != 0) {
            // Increment x by 1
            x += 1;
            // Update n by subtracting 2 raised to the power of the integer part of the base-2 logarithm of n
            n -= (int) Math.pow(2, (int) (Math.log(n) / Math.log(2)));
        }
        // Print the value of x
        System.out.println(x);
        scanner.close();
    }
}
// <END-OF-CODE>
