import java.util.Scanner; // Importing the Scanner class for reading input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        String s = scanner.next(); // Read a string from standard input

        // Count the occurrences of the letter 'o' in the input string 's'
        int n = s.length() - s.replace("o", "").length(); // Calculate the count of 'o'

        // Calculate the result based on the count of 'o' and print it
        // The formula adds 700 to 100 times the count of 'o'
        System.out.println(700 + n * 100);
        
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
