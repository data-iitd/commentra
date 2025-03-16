
import java.util.Scanner;

public class s870102598{
    public static void main(String[] args) {
        // Declare three integer variables a, b, and c
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();

        // Check if c is within the range [a, b]
        if (c >= a && c <= b) {
            // If c is within the range, print "Yes"
            System.out.println("Yes");
        } else {
            // If c is outside the range, print "No"
            System.out.println("No");
        }
    }
}
