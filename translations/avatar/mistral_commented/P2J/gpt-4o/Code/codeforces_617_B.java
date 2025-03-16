import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read the input string
        String a = scanner.nextLine();
        
        // Check if the string contains any '1' character
        if (a.indexOf('1') == -1) {
            // If it doesn't, print 0 and exit the program
            System.out.println(0);
            return;
        }
        
        // Split the string by '1' and calculate the product of the number of zeros in each segment
        String[] segments = a.trim().split("1");
        int productOfZeros = 1;
        
        for (String segment : segments) {
            // Count the number of '0's in the segment and add 1
            productOfZeros *= (segment.length() + 1);
        }
        
        // Finally, print the result
        System.out.println(productOfZeros);
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
