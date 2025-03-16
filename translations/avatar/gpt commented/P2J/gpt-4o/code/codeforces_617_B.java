import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read an input line (not used in further calculations)
        scanner.nextLine();
        
        // Read a string input from the user
        String a = scanner.nextLine();
        
        // Check if the string contains any '1's
        // If there are no '1's, print 0
        // Otherwise, calculate the product of counts of '0's between '1's
        if (a.indexOf('1') == -1) {
            System.out.println(0);
        } else {
            String[] segments = a.trim().split("1");
            int product = 1;
            for (String segment : segments) {
                product *= (segment.length() + 1); // Count '0's in each segment and add 1
            }
            System.out.println(product);
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
