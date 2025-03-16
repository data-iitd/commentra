import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object for reading input from the console
        try (Scanner sc = new Scanner(System.in);) {
            // Call the solve method to process the input
            solve(sc);
        }
    }

    public static void solve(Scanner sc) {
        // Read a string input from the user and convert it to a character array
        char[] a = sc.next().toCharArray();
        
        // Check if any two characters in the array are the same
        if (a[0] == a[1] || a[1] == a[2] || a[2] == a[0]) {
            // If any two characters are the same, print "No"
            System.out.println("No");
        } else {
            // If all characters are different, print "Yes"
            System.out.println("Yes");
        }
    }
}
