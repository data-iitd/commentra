import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare a variable named 's' of type String
        String s;

        // Read a string input from the standard input using Scanner
        Scanner scanner = new Scanner(System.in);
        s = scanner.nextLine();

        // Initialize a for loop to iterate through each character in the string 's'
        for (int i = 0; i < s.length(); i++) {
            // Check if the substring from index 'i+1' contains the character at index 'i'
            if (s.substring(i + 1).contains(String.valueOf(s.charAt(i)))) {
                // If the condition is true, print "no" and exit the program
                System.out.println("no");
                return;
            }
        }

        // If the for loop completes without finding any matching characters, print "yes"
        System.out.println("yes");
    }
}
// <END-OF-CODE>
