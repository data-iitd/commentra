// Import necessary packages
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare and initialize two variables: n of type int and s of type String
        int n;
        String s;

        // Create a Scanner object to read input from the standard input
        Scanner scanner = new Scanner(System.in);

        // Read an integer and a string from the input
        n = scanner.nextInt();
        s = scanner.next();

        // Use the String class to compute and print the result
        System.out.println(countOccurrences(s, "ABC"));
        
        // Close the scanner
        scanner.close();
    }

    // Method to count occurrences of a substring in a string
    public static int countOccurrences(String str, String subStr) {
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
