
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        try (Scanner sc = new Scanner(System.in);) {
            // Call the solve method with the Scanner object
            solve(sc);
        }
    }

    public static void solve(Scanner sc) {
        // Read a string of characters from the user and convert it to a character array
        char[] a = sc.next().toCharArray();

        // Check if any two consecutive characters in the array are the same
        if (a[0] == a[1] || a[1] == a[2] || a[2] == a[0]) {
            // If any two consecutive characters are the same, print "No"
            System.out.println("No");
        } else {
            // If no two consecutive characters are the same, print "Yes"
            System.out.println("Yes");
        }
    }
}

