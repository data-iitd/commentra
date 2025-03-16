
import java.util.Scanner; // Import the Scanner class for input

public class s661916956{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input from the user
        int a = scanner.nextInt(); // Read the first integer from the user
        int b = scanner.nextInt(); // Read the second integer from the user
        int c = scanner.nextInt(); // Read the third integer from the user

        // Check if 'a' is greater than 'b', if so, swap their values
        if (a > b) {
            int temp = a;
            a = b;
            b = temp;
        }

        // Check if 'b' is greater than 'c', if so, swap their values
        if (b > c) {
            int temp = b;
            b = c;
            c = temp;
        }

        // Check again if 'a' is greater than 'b', if so, swap their values
        if (a > b) {
            int temp = a;
            a = b;
            b = temp;
        }

        // Output the sorted values of a, b, and c
        System.out.println(a + " " + b + " " + c); // Output the sorted values of a, b, and c

        scanner.close(); // Close the Scanner object to release system resources
    }
}
