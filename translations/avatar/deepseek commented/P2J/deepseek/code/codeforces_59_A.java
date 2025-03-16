import java.util.Scanner;

public class CaseChanger {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
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
        if (cu > cl) {  // If there are more uppercase letters than lowercase letters.
            txt = txt.toUpperCase();  // Convert the entire text to uppercase.
        } else {  // If there are more lowercase letters than uppercase letters or equal counts.
            txt = txt.toLowerCase();  // Convert the entire text to lowercase.
        }

        System.out.println(txt);  // Printing the result stored in `txt`.
    }
}
