// Include the Scanner library for input and output operations.
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a new Scanner object.
        int x = sc.nextInt(); // Read an integer from the standard input and store it in x.
        int ans = x + x*x + x*x*x; // Calculate the result by adding x, x*x, and x*x*x.
        System.out.println(ans); // Print the result to the standard output.
    }
}
