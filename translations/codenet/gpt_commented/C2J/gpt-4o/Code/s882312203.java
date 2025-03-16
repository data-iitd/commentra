import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare a character array to hold the input string (max length 25)
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();

        // Loop through each character in the string
        for (int j = 0; j < s.length(); j++) {
            // Compare the current character with every other character in the string
            for (int i = 0; i < s.length(); i++) {
                // Check if the characters are the same and they are not the same position
                if (i != j && s.charAt(i) == s.charAt(j)) {
                    // If a duplicate character is found, print "no" and exit the program
                    System.out.println("no");
                    return;
                }
            }
        }

        // If no duplicates were found, print "yes"
        System.out.println("yes");
    }
}
// <END-OF-CODE>
