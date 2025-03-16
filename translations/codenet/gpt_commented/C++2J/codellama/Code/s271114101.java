import java.util.Scanner; // Import the Scanner class for input operations

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a Scanner object to read input from the command line

        int a = sc.nextInt(); // Read the first integer from the user
        int b = sc.nextInt(); // Read the second integer from the user
        int c = sc.nextInt(); // Read the third integer from the user

        // Check if any two of the three numbers sum up to the third number
        // If a + b equals c, or b + c equals a, or a + c equals b, print "Yes"
        // Otherwise, print "No"
        System.out.println((a + b == c || b + c == a || a + c == b) ? "Yes" : "No");
    }
}

