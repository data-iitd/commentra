
import java.util.Scanner;  // Importing the Scanner class from the java.util package.

public class codeforces_59_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Creating a Scanner object to read input from the user.
        String txt = scanner.nextLine();  // Reading the input text from the user and storing it in the variable `txt`.
        int cu = 0;  // Initializing the counter for uppercase letters to zero.
        int cl = 0;  // Initializing the counter for lowercase letters to zero.

        // Looping through each character in the input text `txt` to count the number of uppercase and lowercase letters.
        for (int i = 0; i < txt.length(); i++) {
            char z = txt.charAt(i);  // Extracting the current character `z` from the input text `txt`.
            if (Character.isLowerCase(z)) {  // Checking if the current character `z` is lowercase.
                cl = cl + 1;  // Incrementing the counter for lowercase letters if `z` is lowercase.
            } else {  // If `z` is not lowercase, it must be uppercase.
                cu = cu + 1;  // Incrementing the counter for uppercase letters.
            }
        }

        // Comparing the counts of uppercase and lowercase letters to decide the case of the output.
        String out = "";  // Initializing an empty string to store the result.
        if (cu > cl) {  // If there are more uppercase letters than lowercase letters.
            out = txt.toUpperCase();  // Convert the entire text to uppercase and store it in the variable `out`.
        } else {  // If there are more lowercase letters than uppercase letters or equal counts.
            out = txt.toLowerCase();  // Convert the entire text to lowercase and store it in the variable `out`.
        }

        System.out.println(out);  // Printing the result stored in `out`.
    }
}
