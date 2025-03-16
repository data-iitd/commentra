
import java.util.Scanner;

public class s989417036{
    public static void main(String[] args) {
        // Declare variables to hold input values and loop counter
        int a, b, c, d, e, i;

        // Create a new Scanner object to read user input
        Scanner scanner = new Scanner(System.in);

        // Read three integers from user input
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();

        // Check if b is less than or equal to c
        if (b <= c) {
            // If true, print "NO" and exit the program
            System.out.println("NO");
            return;
        } else {
            // Initialize d with the value of a
            d = a;

            // Calculate the remainder of d when divided by b
            e = d % b;

            // Loop through values from 0 to b-1
            for (i = 0; i < b; i++) {
                // Update d to be the remainder of d when divided by b
                d = d % b;

                // Check if d is equal to c
                if (d == c) {
                    // If true, print "YES" and exit the program
                    System.out.println("YES");
                    return;
                } 
                // Check if this is not the first iteration and d is equal to c
                else if (i!= 0 && d == c) {
                    // If true, print "NO" and exit the program
                    System.out.println("NO");
                    return;
                }

                // Increment d by the value of a
                d += a;
            }
        }

        // If no conditions were met, print "NO"
        System.out.println("NO");
    }
}
