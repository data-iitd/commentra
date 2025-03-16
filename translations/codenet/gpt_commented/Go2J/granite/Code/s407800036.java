
import java.util.Scanner;

public class s407800036{
    public static void main(String[] args) {
        // Declare variables A, B, and C to hold integer values
        Scanner scanner = new Scanner(System.in);
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        int C = scanner.nextInt();

        // Check if C is within the range defined by A and B (inclusive)
        if (C >= A && C <= B) {
            // If C is within the range, print "Yes"
            System.out.println("Yes");
        } else {
            // If C is outside the range, print "No"
            System.out.println("No");
        }
    }
}
