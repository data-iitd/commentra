
import java.util.*;

public class Main {

    public static void main(String[] args) {
        // Declare two long long integer variables to store input values
        long x, y;

        // Read two integer values from standard input
        Scanner sc = new Scanner(System.in);
        x = sc.nextLong();
        y = sc.nextLong();

        // Check if the absolute difference between x and y is less than or equal to 1
        if (Math.abs(x - y) <= 1) {
            // If the condition is true, output "Brown"
            System.out.println("Brown");
        } else {
            // If the condition is false, output "Alice"
            System.out.println("Alice");
        }
    }
}

