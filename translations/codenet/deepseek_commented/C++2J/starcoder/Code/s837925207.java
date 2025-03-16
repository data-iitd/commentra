import java.util.*; // Import the Scanner and other classes.

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a Scanner object.
        int x, ans = 0; // Declare two integer variables x and ans.

        x = sc.nextInt(); // Read an integer from the standard input and store it in x.

        ans = x + x*x + x*x*x; // Calculate the result by adding x, x*x, and x*x*x.

        System.out.println(ans); // Print the result to the standard output.
    }
}

