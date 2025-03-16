
import java.util.Arrays;
import java.util.Scanner;

public class s240156356{
    public static void main(String[] args) {
        // Declare two strings to hold the input
        String str1, str2;
        
        // Create a Scanner object to read input from the standard input
        Scanner scanner = new Scanner(System.in);
        
        // Read two strings from the standard input
        str1 = scanner.next();
        str2 = scanner.next();

        // Sort the first string in ascending order
        char[] charArray1 = str1.toCharArray();
        Arrays.sort(charArray1);
        str1 = new String(charArray1);
        
        // Sort the second string in descending order
        char[] charArray2 = str2.toCharArray();
        Arrays.sort(charArray2);
        str2 = new String(charArray2);

        // Determine the length of the shorter string for the loop
        int loop = str1.length() > str2.length()? str2.length() : str1.length();
        
        // Initialize a flag to track if the condition is met
        boolean flag = false;

        // Loop through the characters of both strings up to the length of the shorter one
        for (int i = 0; loop > i; i++) {
            char ch1 = str1.charAt(i); // Get the character from the first string
            char ch2 = str2.charAt(i); // Get the character from the second string

            // Check if the characters are equal
            if (ch1 == ch2) {
                // If we are at the last character of the shorter string and str1 is shorter
                if (loop == i + 1 && str1.length() < str2.length()) {
                    flag = true; // Set the flag to true
                    break; // Exit the loop
                } else {
                    continue; // Continue to the next iteration
                }
            } else {
                // If the character from str2 is greater than that from str1
                if (ch2 > ch1) {
                    flag = true; // Set the flag to true
                    break; // Exit the loop
                } else {
                    break; // Exit the loop if ch1 is greater
                }
            }
        }

        // Output the result based on the flag's value
        if (flag) {
            System.out.println("Yes"); // Condition met
        } else {
            System.out.println("No"); // Condition not met
        }
    }
}
