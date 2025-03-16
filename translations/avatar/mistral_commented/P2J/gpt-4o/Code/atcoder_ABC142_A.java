import java.util.Scanner;

public class Main {
    // Define a method to read an integer input from the user
    public static int nextInt() {
        Scanner scanner = new Scanner(System.in);
        return scanner.nextInt();
    }

    public static void main(String[] args) {
        // Read an integer `n` from the user
        int n = nextInt();
        // Initialize a variable `t` to zero
        int t = 0;

        // Iterate through the range of integers from 0 to n-1
        for (int i = 0; i < n; i++) {
            // Check if the index i is odd
            if ((i + 1) % 2 == 1) {
                // If it is odd, increment the variable t by 1
                t++;
            }
        }
        // Print the result t/n as the output
        System.out.println((double) t / n);
    }
}
// <END-OF-CODE>
