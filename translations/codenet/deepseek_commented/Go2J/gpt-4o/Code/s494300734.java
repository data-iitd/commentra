import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input
        String s = scanner.next(); // Read a string from standard input
        
        String ans = "No"; // Initialize the answer variable with "No"
        
        // Check if 'C' appears before the last occurrence of 'F' in the string s
        if (s.indexOf('C') < s.lastIndexOf('F')) {
            ans = "Yes"; // Update ans to "Yes" if the condition is true
        }
        
        // Check if 'C' does not appear in the string s
        if (s.indexOf('C') < 0) {
            ans = "No"; // Update ans to "No" if the condition is true
        }
        
        System.out.println(ans); // Print the final value of ans
    }
}
// <END-OF-CODE>
