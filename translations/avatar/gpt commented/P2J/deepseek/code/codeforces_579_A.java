import java.util.Scanner;  // Import the Scanner class to read input from the user

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object to read input
        int n = scanner.nextInt();  // Read an integer input from the user

        // Initialize a counter variable to track the number of iterations
        int x = 1;

        // Continue looping while n is not a power of 2
        while (Math.log(n) / Math.log(2) % 1 != 0) {
            x += 1;  // Increment the counter for each iteration
            // Subtract the largest power of 2 less than or equal to n from n
            n -= (int)Math.pow(2, (int)(Math.log(n) / Math.log(2)));
        }

        // Print the final count of iterations
        System.out.println(x);
    }
}
