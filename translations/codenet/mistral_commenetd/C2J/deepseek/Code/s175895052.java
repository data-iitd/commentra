import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String n = scanner.next(); // Read a string of characters from the standard input stream

        // Check if the first three characters of the input string form an identical sequence
        if ((n.charAt(0) == n.charAt(1) && n.charAt(1) == n.charAt(2)) ||
            (n.charAt(1) == n.charAt(2) && n.charAt(2) == n.charAt(3))) {
            // If the condition is true, print "Yes" to the standard output stream
            System.out.println("Yes");
        } else {
            // If the condition is false, print "No" to the standard output stream
            System.out.println("No");
        }
    }
}
