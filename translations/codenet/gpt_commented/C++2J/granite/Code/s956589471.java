
import java.util.Scanner; // Import the Scanner class for input

public class s956589471{
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Declare variables to hold input values
        int a, b, c, d, e, k;

        // Read six integers from standard input
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        d = scanner.nextInt();
        e = scanner.nextInt();
        k = scanner.nextInt();

        // Check if the difference between e and a is less than or equal to k
        // If true, print "Yay!", otherwise print ":("
        if (e - a <= k) {
            System.out.println("Yay!");
        } else {
            System.out.println(":(");
        }

        // Close the Scanner object to release system resources
        scanner.close();
    }
}
