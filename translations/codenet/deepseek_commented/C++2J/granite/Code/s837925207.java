
import java.util.*; // Import the Scanner class from the java.util package.

public class s837925207{ // Define a class named s837925207.
    public static void main(String[] args) { // Define the main method as the entry point of the program.
        Scanner sc = new Scanner(System.in); // Create a Scanner object to read input from the standard input.
        int x = sc.nextInt(); // Read an integer from the standard input and store it in x.
        int ans = x + x*x + x*x*x; // Calculate the result by adding x, x*x, and x*x*x.
        System.out.println(ans); // Print the result to the standard output.
    }
}
