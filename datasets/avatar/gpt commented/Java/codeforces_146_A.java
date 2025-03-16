import java.util.*; // Importing the utility package for Scanner
import static java.lang.Math.*; // Importing static members of the Math class

public class Main {
    public static void main(String args[]) {
        // Creating a Scanner object to read input from the user
        Scanner in = new Scanner(System.in);
        
        // Initializing variables to hold the sum of the first half and the second half of the digits
        int x = 0, y = 0;
        int t = 0; // Variable to check if there are any digits other than '4' or '7'
        
        // Reading the length of the number and the number itself as a string
        int n = in.nextInt();
        String str = in.next();
        
        // Converting the string to a character array for easier manipulation
        char l[] = new char[str.length()];
        l = str.toCharArray();
        
        // Checking if all characters in the string are either '4' or '7'
        for (int i = 0; i < n; i++) {
            if (l[i] != '4' && l[i] != '7') {
                t = 1; // Set t to 1 if a character is found that is not '4' or '7'
            }
        }
        
        // If t is set, print "NO" indicating the number is not lucky
        if (t == 1) {
            System.out.println("NO");
        } else {
            // Calculate the sum of the first half of the digits
            for (int i = 0; i < n / 2; i++) {
                x = x + Character.getNumericValue(l[i]);
            }
            // Calculate the sum of the second half of the digits
            for (int i = n - 1; i > (n / 2) - 1; i--) {
                y = y + Character.getNumericValue(l[i]);
            }
            // Compare the two sums and print "YES" if they are equal, otherwise print "NO"
            if (x == y) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}
