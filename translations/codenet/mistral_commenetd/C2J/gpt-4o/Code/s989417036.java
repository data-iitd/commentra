import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables
        int a, b, c, d, e, i;

        // Initialize variables with Scanner
        Scanner scanner = new Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();

        // Check if b is less than or equal to c
        if (b <= c) {
            // If so, print "NO" and exit
            System.out.println("NO");
            return;
        } else {
            // Initialize d with a and e with the remainder of a divided by b
            d = a;
            e = d % b;

            // Iterate through b using a for loop
            for (i = 0; i < b; i++) {
                // Update d by calculating the remainder of d divided by b
                d = d % b;

                // If d is equal to c, print "YES" and exit
                if (d == c) {
                    System.out.println("YES");
                    return;
                }
                // If d is already equal to c and i is not the first iteration, print "NO" and exit
                else if (i != 0 && d == c) {
                    System.out.println("NO");
                    return;
                }

                // Update d by adding a
                d += a;
            }
        }

        // If the loop finishes without finding c, print "NO" and exit
        System.out.println("NO");
    }
}
// <END-OF-CODE>
