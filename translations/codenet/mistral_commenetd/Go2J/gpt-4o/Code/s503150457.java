import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare empty strings s1, s2, and s3 for user input
        String s1, s2, s3;

        // Create a Scanner object to read user input
        Scanner scanner = new Scanner(System.in);

        // Read user input for strings s1, s2, and s3
        s1 = scanner.next();
        s2 = scanner.next();
        s3 = scanner.next();

        // Get the first character of each string and convert to uppercase
        String result = String.valueOf(s1.charAt(0)).toUpperCase() +
                        String.valueOf(s2.charAt(0)).toUpperCase() +
                        String.valueOf(s3.charAt(0)).toUpperCase();

        // Print the concatenated uppercase first character of each string
        System.out.println(result);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
