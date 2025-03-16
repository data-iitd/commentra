import java.util.Scanner; // Importing the Scanner class for reading input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int n = scanner.nextInt(); // Read the length of the string
        String s = scanner.next(); // Read the input string

        // Count occurrences of the substring "ABC" in the string s
        int count = countOccurrences(s, "ABC");
        System.out.println(count); // Print the count
    }

    // Method to count occurrences of a substring in a string
    private static int countOccurrences(String s, String sub) {
        int count = 0;
        int index = 0;

        // Loop to find all occurrences of the substring
        while ((index = s.indexOf(sub, index)) != -1) {
            count++;
            index += sub.length(); // Move index forward to continue searching
        }
        return count; // Return the total count
    }
}

// <END-OF-CODE>
