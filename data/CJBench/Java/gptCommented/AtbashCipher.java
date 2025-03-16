import java.util.Scanner;

public class Main {
    // Variable to hold the string that will be converted
    private String toConvert;

    // Default constructor
    public Main() {
    }

    // Constructor that initializes the string to convert
    public Main(String str) {
        this.toConvert = str;
    }

    // Getter method to retrieve the string to convert
    public String getString() {
        return toConvert;
    }

    // Setter method to set the string to convert
    public void setString(String str) {
        this.toConvert = str;
    }

    // Method to check if a character is an uppercase letter
    private boolean isCapital(char ch) {
        return ch >= 'A' && ch <= 'Z';
    }

    // Method to check if a character is a lowercase letter
    private boolean isSmall(char ch) {
        return ch >= 'a' && ch <= 'z';
    }

    // Method to convert the string by reversing the alphabetic characters
    public String convert() {
        StringBuilder convertedString = new StringBuilder(); // StringBuilder to hold the converted result
        // Iterate through each character in the string to convert
        for (char ch : toConvert.toCharArray()) {
            // If the character is lowercase, convert it to its reverse
            if (isSmall(ch)) {
                convertedString.append((char) ('z' - (ch - 'a')));
            // If the character is uppercase, convert it to its reverse
            } else if (isCapital(ch)) {
                convertedString.append((char) ('Z' - (ch - 'A')));
            // If the character is neither, append it unchanged
            } else {
                convertedString.append(ch);
            }
        }
        return convertedString.toString(); // Return the converted string
    }

    // Main method to run the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        String inputText = scanner.nextLine(); // Read input from the user
        Main cipher = new Main(inputText); // Create an instance of Main with the input text
        String result = cipher.convert(); // Convert the input text
        System.out.println("Converted Text: " + result); // Print the converted text
        scanner.close(); // Close the scanner to free resources
    }
}
