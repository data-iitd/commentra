import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare a string variable to hold user input
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String str = scanner.nextLine();

        // Convert the string to a character array to modify specific characters
        char[] charArray = str.toCharArray();

        // Replace the character at index 5 with a space
        if (charArray.length > 5) {
            charArray[5] = ' ';
        }

        // Replace the character at index 13 with a space
        if (charArray.length > 13) {
            charArray[13] = ' ';
        }

        // Convert the character array back to a string
        String modifiedStr = new String(charArray);

        // Print the modified string to the console
        System.out.println(modifiedStr);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
