// Import necessary packages
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Declare two variables, n and s
        int n = scanner.nextInt();
        String s = scanner.next();
        
        // Count the occurrences of "ABC" in the string s
        int count = countOccurrences(s, "ABC");
        
        // Print the result
        System.out.println(count);
        
        // Close the scanner
        scanner.close();
    }

    // Method to count occurrences of a substring in a string
    private static int countOccurrences(String str, String subStr) {
        int count = 0;
        int index = 0;

        // Loop to find all occurrences of subStr in str
        while ((index = str.indexOf(subStr, index)) != -1) {
            count++;
            index += subStr.length(); // Move index forward
        }
        
        return count;
    }
}

// <END-OF-CODE>
