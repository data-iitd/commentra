
import java.util.Scanner;

public class s218395502{
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Declare three integer variables to hold the input values
        int a, b, c;

        // Read three integers from the user input
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();

        // Check if the number formed by a, b, and c is divisible by 4
        // The number is formed as 100*a + 10*b + c
        if ((100 * a + 10 * b + c) % 4 == 0) {
            // If the number is divisible by 4, output "YES"
            System.out.println("YES");
        }
        else {
            // If the number is not divisible by 4, output "NO"
            System.out.println("NO");
        }

        // Close the Scanner object to release system resources
        scanner.close();
    }
}
