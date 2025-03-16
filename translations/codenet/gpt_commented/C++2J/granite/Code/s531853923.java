
import java.util.Scanner;

public class s531853923{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Declare four integer variables to hold input values
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        int d = scanner.nextInt();

        // Check if the product of a and b is odd and the sum of c and d is odd
        if (a * b % 2 == 1 && (c + d) % 2 == 1) {
            // If both conditions are true, output "No"
            System.out.println("No");
        } else {
            // If either condition is false, output "Yes"
            System.out.println("Yes");
        }
    }
}
