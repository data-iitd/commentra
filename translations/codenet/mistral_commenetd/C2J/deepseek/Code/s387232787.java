import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] c = new int[26]; // Initialize an array 'c' of size 26 to store the count of each character.

        while (scanner.hasNext()) {
            String str = scanner.next(); // Read the input string.

            // Initialize a pointer 'p' to traverse the string 'str'.
            for (char p : str.toCharArray()) {
                // Use nested if conditions to check if the current character is a lowercase or uppercase letter.
                if ('a' <= p && p <= 'z') {
                    // Increment the count of the corresponding character in the 'c' array.
                    c[p - 'a']++;
                } else if ('A' <= p && p <= 'Z') {
                    // Increment the count of the corresponding character in the 'c' array.
                    c[p - 'A']++;
                }
            }
        }
        // Use a loop to print the count of each character and its corresponding character.
        for (int i = 0; i < 26; i++) {
            System.out.println((char)('a' + i) + " : " + c[i]);
        }
        // Return 0 to indicate successful execution of the program.
    }
}
