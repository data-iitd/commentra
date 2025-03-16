
import java.util.Scanner;
public class Main {
    private String toConvert;
    public Main() {
    }
    // Constructor that initializes the string to be converted
    public Main(String str) {
        this.toConvert = str;
    }
    // Getter method to retrieve the string to be converted
    public String getString() {
        return toConvert;
    }
    // Setter method to set the string to be converted
    public void setString(String str) {
        this.toConvert = str;
    }
    // Helper method to check if a character is uppercase
    private boolean isCapital(char ch) {
        return ch >= 'A' && ch <= 'Z';
    }
    // Helper method to check if a character is lowercase
    private boolean isSmall(char ch) {
        return ch >= 'a' && ch <= 'z';
    }
    // Method to convert the string based on the given logic
    public String convert() {
        StringBuilder convertedString = new StringBuilder();
        for (char ch : toConvert.toCharArray()) {
            if (isSmall(ch)) {
                convertedString.append((char) ('z' - (ch - 'a')));
            } else if (isCapital(ch)) {
                convertedString.append((char) ('Z' - (ch - 'A')));
            } else {
                convertedString.append(ch);
            }
        }
        return convertedString.toString();
    }
    // Main method to run the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String inputText = scanner.nextLine();
        Main cipher = new Main(inputText);
        String result = cipher.convert();
        System.out.println("Converted Text: " + result);
        scanner.close();
    }
}

This code provides a clear structure with comments explaining each part, making it easier to understand and maintain.