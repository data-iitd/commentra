
import java.util.Scanner;

public class s430241485{
    public static void main(String[] args) {
        // Declare two string variables to hold input values
        String s, t;
        
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Read two strings from standard input
        s = scanner.next();
        t = scanner.next();
        
        // Print the concatenation of the second string followed by the first string
        System.out.println(t + s);
    }
}
// END-OF-CODE