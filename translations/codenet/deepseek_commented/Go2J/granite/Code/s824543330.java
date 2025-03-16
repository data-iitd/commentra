
import java.util.Scanner;

public class s824543330{
    public static void main(String[] args) {
        // Declare two integer variables a and b
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        
        // Check if the product of a and b is even or odd
        if (a * b % 2 == 0) {
            // If the product is even, print "Even"
            System.out.println("Even");
        } else {
            // If the product is odd, print "Odd"
            System.out.println("Odd");
        }
    }
}
// END-OF-CODE