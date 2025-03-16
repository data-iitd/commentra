
import java.util.Scanner;
public class atcoder_ABC164_A{
    public static void main(String[] args) {
        // Create a Scanner object to read the values of S and W from the user
        Scanner scanner = new Scanner(System.in);
        // Read the values of S and W from the user
        int S = scanner.nextInt();
        int W = scanner.nextInt();
        // Check if the value of W is greater than or equal to S
        // If true, print "unsafe"
        if (S <= W) {
            System.out.println("unsafe");
        } else {
            System.out.println("safe");
        }
    }
}
// Ensure the main function is called only when the script is executed directly

Translate the above Java code to C++ and end with comment "