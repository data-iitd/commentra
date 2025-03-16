
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Declare three long long integer variables to hold input values
        long a, b, c;

        // Read three long long integers from standard input
        Scanner sc = new Scanner(System.in);
        a = sc.nextLong();
        b = sc.nextLong();
        c = sc.nextLong();

        // Calculate the value of d as the difference between c and the sum of a and b
        long d = c - a - b;

        // Check if d is positive and if 4 times the product of a and b is less than d squared
        if ((d > 0) && ((4 * a * b) < d * d)) {
            // If the condition is true, print "Yes"
            System.out.println("Yes");
        } else {
            // If the condition is false, print "No"
            System.out.println("No");
        }
    }
}
