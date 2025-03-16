// Step 1: Include the standard input/output library.
import java.util.Scanner;

// Step 2: Define the main function.
public class Main {
    public static void main(String[] args) {
        // Step 3: Declare two integer variables a and b.
        int a, b;

        // Step 4: Read two integers from the user input.
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        b = sc.nextInt();

        // Step 5: Check if the product of 500 and a is greater than or equal to b.
        if (500 * a >= b) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
