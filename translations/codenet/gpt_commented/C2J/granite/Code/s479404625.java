
import java.util.Scanner;

public class s479404625{
    public static void main(String[] args) {
        // Declare character arrays to hold three strings
        char A[] = new char[20];
        char B[] = new char[20];
        char C[] = new char[20];

        // Create a Scanner object to read user input
        Scanner scanner = new Scanner(System.in);

        // Read three strings from user input
        scanner.nextLine();
        scanner.nextLine().getChars(0, 20, A, 0);
        scanner.nextLine().getChars(0, 20, B, 0);
        scanner.nextLine().getChars(0, 20, C, 0);

        // Calculate the lengths of the first two strings
        int la = A.length, lb = B.length;

        // Check if the last character of A is the same as the first character of B
        // and if the last character of B is the same as the first character of C
        if (A[la - 1] == B[0] && B[lb - 1] == C[0])
        {
            // If both conditions are true, print "YES"
            System.out.println("YES");
        }
        else
        {
            // If either condition is false, print "NO"
            System.out.println("NO");
        }

        // Close the Scanner object to release system resources
        scanner.close();
    }
}
