import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Get the input string from the user
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();

        // Split the input string using '.' as delimiter and store the parts in an array
        String[] parts = input.split("\\.");

        // Extract the first and second parts of the array
        char[] s = parts[0].toCharArray();
        char[] p = parts[1].toCharArray();

        // Get the last character of the string 's'
        char lastChar = s[s.length - 1];

        // Check if the last character of the string 's' is '9'
        if (lastChar == '9') {
            // If yes, print the message "GOTO Vasilisa."
            System.out.println("GOTO Vasilisa.");
        } 
        // Else, if the last character is not '9' and the integer value of the first part of 'p' is less than 5
        else if (lastChar != '9' && Integer.parseInt(String.valueOf(p[0])) < 5) {
            // Concatenate all the characters of 's' to form a string
            String sString = new String(s);
            // Print the string 's'
            System.out.println(sString);
        } 
        // Else, if the last character is not '9' and the integer value of the first part of 'p' is greater than or equal to 5
        else {
            // Concatenate all the characters of 's' to form a string
            String sString = new String(s);
            // Increment the last character of the string 's' by 1
            sString = String.valueOf(Integer.parseInt(sString) + 1);
            // Print the updated string 's'
            System.out.println(sString);
        }

        scanner.close();
    }
}
// <END-OF-CODE>
