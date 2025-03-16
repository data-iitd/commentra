import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables to hold the integer input and the string input
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read an integer from standard input
        String s = scanner.next(); // Read a string from standard input
        
        // Count the occurrences of the substring "ABC" in the input string
        int count = countOccurrences(s, "ABC");
        
        // Print the result
        System.out.println(count);
        
        scanner.close();
    }
    
    // Method to count occurrences of a substring in a string
    private static int countOccurrences(String str, String subStr) {
        int count = 0;
        int index = 0;
        
        while ((index = str.indexOf(subStr, index)) != -1) {
            count++;
            index += subStr.length(); // Move past the last found occurrence
        }
        
        return count;
    }
}

// <END-OF-CODE>
