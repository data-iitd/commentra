
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize a Scanner object to read input from the standard input stream
        try (Scanner sc = new Scanner(System.in);) {
            // Call the solve method with the Scanner object as an argument
            solve(sc);
        }
    }

    public static void solve(Scanner sc) {
        // Read the next input as a character array `a`
        char[] a = sc.next().toCharArray();

        // Check if the first, second, or third character of the array `a` is equal to any of the other two characters
        if (a[0] == a[1] || a[1] == a[2] || a[2] == a[0]) {
            // If so, print "No" and exit the method
            System.out.println("No");
            return;
        }

        // If the first logical block fails, it means that the first, second, and third characters of the array `a` are all different
        // In this case, print "Yes"
        System.out.println("Yes");
    }
}