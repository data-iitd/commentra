
import java.util.Scanner;

public class s410235811{
    public static void main(String[] args) {
        // Create a Scanner object to read user input
        Scanner scanner = new Scanner(System.in);

        // Read an integer value from the user
        int n = scanner.nextInt();

        // Check if the number is even
        if (n % 2 == 0) {
            // If the number is even, print half of the number
            System.out.println(n / 2);
        } else {
            // If the number is odd, print half of the number plus one
            System.out.println((n / 2) + 1);
        }

        // Close the Scanner object
        scanner.close();
    }
}
// END-OF-CODE