import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Creating a Scanner object to take input from the user.
        String txt = scanner.nextLine();  // Taking input from the user and storing it in the variable `txt`.
        int cu = 0;  // Initializing the counter for uppercase letters to zero.
        int cl = 0;  // Initializing the counter for lowercase letters to zero.

        // Looping through each character in the input text `txt` to count the number of uppercase and lowercase letters.
        for (char z : txt.toCharArray()) {
            if (Character.isLowerCase(z)) {  // Checking if the current character `z` is lowercase.
                cl++;  // Incrementing the counter for lowercase letters if `z` is lowercase.
            } else {  // If `z` is not lowercase, it must be uppercase.
                cu++;  // Incrementing the counter for uppercase letters.
            }
        }

        // Comparing the counts of uppercase and lowercase letters to decide the case of the output.
        String out;  // Declaring the output variable.
        if (cu > cl) {  // If there are more uppercase letters than lowercase letters.
            out = txt.toUpperCase();  // Convert the entire text to uppercase.
        } else {  // If there are more lowercase letters than uppercase letters or equal counts.
            out = txt.toLowerCase();  // Convert the entire text to lowercase.
        }

        System.out.println(out);  // Printing the result stored in `out`.
        scanner.close();  // Closing the scanner to prevent resource leaks.
    }
}
// <END-OF-CODE>
