import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next(); // Read the input string from standard input

        for (int i = 0; i < s.length(); i++) { // Iterate over each character in the string
            char currentChar = s.charAt(i);
            if (s.indexOf(currentChar, i + 1) != -1) { // Check if the character appears again in the substring
                System.out.println("no"); // If it does, print "no" and exit
                return;
            }
        }

        System.out.println("yes"); // If no character appears again, print "yes"
    }
}
// <END-OF-CODE>
