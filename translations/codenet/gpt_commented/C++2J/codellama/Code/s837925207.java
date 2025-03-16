// Include the Scanner library for input and output
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables x for input and ans for the result
        int x, ans = 0;

        // Create a Scanner object for input
        Scanner sc = new Scanner(System.in);

        // Read an integer input from the user
        x = sc.nextInt();

        // Calculate the result as the sum of x, x squared, and x cubed
        ans = x + x*x + x*x*x;

        // Output the calculated result to the console
        System.out.println(ans);

        // Close the Scanner object
        sc.close();
    }
}

