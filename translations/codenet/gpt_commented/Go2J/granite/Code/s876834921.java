
import java.util.Scanner;

public class s876834921{
    public static void main(String[] args) {
        // Declare a string variable to hold user input
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        
        // Replace occurrences of "dream" with "D"
        s = s.replaceAll("dream", "D");
        
        // Replace occurrences of "erase" with "E"
        s = s.replaceAll("erase", "E");
        
        // Remove occurrences of "Der" from the string
        s = s.replaceAll("Der", "");
        
        // Remove occurrences of "Er" from the string
        s = s.replaceAll("Er", "");
        
        // Remove occurrences of "D" from the string
        s = s.replaceAll("D", "");
        
        // Remove occurrences of "E" from the string
        s = s.replaceAll("E", "");
        
        // Trim any leading or trailing whitespace from the string
        s = s.trim();

        // Check if the resulting string is empty
        if (s.isEmpty()) {
            // If the string is empty, print "YES"
            System.out.println("YES");
        } else {
            // If the string is not empty, print "NO"
            System.out.println("NO");
        }
    }
}
