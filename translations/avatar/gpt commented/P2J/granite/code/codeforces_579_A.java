
import java.util.Scanner;  // Import the Scanner class to read user input

public class codeforces_579_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object to read user input
        int n = scanner.nextInt();  // Read an integer input from the user

        int x = 1;  // Initialize a counter variable to track the number of iterations

        // Continue looping while n is not a power of 2
        while (Math.log10(n) / Math.log10(2) % 1!= 0) {
            x++;  // Increment the counter for each iteration
            // Subtract the largest power of 2 less than or equal to n from n
            n -= (int) Math.pow(2, Math.floor(Math.log10(n) / Math.log10(2)));
        }

        System.out.println(x);  // Print the final count of iterations
    }
}
