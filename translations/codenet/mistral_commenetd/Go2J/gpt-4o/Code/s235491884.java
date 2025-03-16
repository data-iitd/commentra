// Importing necessary packages
import java.util.Scanner;

public class Main {
    // The main method is the entry point of the program
    public static void main(String[] args) {
        // Create a Scanner object to read input from the standard input
        Scanner scanner = new Scanner(System.in);
        
        // Declare a variable 's' of type String
        String s = scanner.nextLine();
        
        // Count the number of occurrences of the substring "o" in the string 's'
        int n = countOccurrences(s, "o");
        
        // Calculate the result by adding 700 to the product of 100 and the number of occurrences of "o" in the string
        int result = 700 + n * 100;
        
        // Print the result to the standard output
        System.out.println(result);
        
        // Close the scanner
        scanner.close();
    }
    
    // Method to count occurrences of a substring in a string
    public static int countOccurrences(String str, String subStr) {
        int count = 0;
        int index = 0;
        
        // Loop to find all occurrences of the substring
        while ((index = str.indexOf(subStr, index)) != -1) {
            count++;
            index += subStr.length();
        }
        
        return count;
    }
}

// <END-OF-CODE>
