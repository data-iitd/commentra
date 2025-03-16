

import java.util.Scanner;

public class s407800036{
    public static void main(String[] args) {
        // Code for A - Between Two Integers
        Scanner scanner = new Scanner(System.in);
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        int C = scanner.nextInt();

        // Read three integers A, B, and C from standard input
        // Check if C is between A and B (inclusive)
        if (C >= A && C <= B) {
            // If C is between A and B, print "Yes"
            System.out.println("Yes");
        } else {
            // If C is not between A and B, print "No"
            System.out.println("No");
        }
    }
}
