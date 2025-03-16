import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next(); // Read input from the user and store it in the variable 's'
        
        // Iterate over each character in the string 's'
        for (int i = 0; i < s.length(); i++) {
            // Check if the current character exists in the substring that follows it
            if (s.substring(i + 1).contains(String.valueOf(s.charAt(i)))) {
                // If the character is found in the remaining substring, print "no" and exit
                System.out.println("no");
                return; // Exit the program
            }
        }

        // If no duplicate characters were found, print "yes"
        System.out.println("yes");
    }
}

// <END-OF-CODE>
