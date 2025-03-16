import java.util.Scanner; // Import the Scanner class for reading input

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the standard input
        Scanner scanner = new Scanner(System.in);

        // Read a string input from the standard input
        String s = scanner.nextLine();

        // Check if the length of the string "s" is greater than or equal to 4
        // and if its first four characters are "YAKI"
        if (s.length() >= 4 && s.substring(0, 4).equals("YAKI")) {
            // If the condition is true, print the word "Yes" to the standard output
            System.out.println("Yes");
        } else {
            // If the condition is false, print the word "No" to the standard output
            System.out.println("No");
        }
    }
}
