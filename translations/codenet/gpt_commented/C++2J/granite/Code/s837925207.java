
import java.util.*; // Import the Scanner class for input

public class s837925207{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a Scanner object to read input from the console
        int x = sc.nextInt(); // Read an integer input from the user
        int ans = x + x*x + x*x*x; // Calculate the result as the sum of x, x squared, and x cubed
        System.out.println(ans); // Output the calculated result to the console
    }
}
