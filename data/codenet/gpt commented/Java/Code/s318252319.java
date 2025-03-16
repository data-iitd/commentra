import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read a string input from the user
        String s = sc.next();
        
        // Extract the last character of the string, convert it to an integer
        int n = Integer.parseInt(s.substring(s.length() - 1, s.length()));
        
        // Check the value of n and print corresponding output
        if (n == 3) {
            // If n is 3, print "bon"
            System.out.println("bon");
        } else if (n == 0 || n == 1 || n == 6 || n == 8) {
            // If n is 0, 1, 6, or 8, print "pon"
            System.out.println("pon");
        } else {
            // For all other values of n, print "hon"
            System.out.println("hon");
        }
        
        // Close the Scanner to free up resources
        sc.close();
    }
}
