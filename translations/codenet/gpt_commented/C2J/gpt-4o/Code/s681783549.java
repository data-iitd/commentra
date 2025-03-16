import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare a Scanner for input and a character array to store input
        Scanner scanner = new Scanner(System.in);
        char[] S = new char[6];

        // Read a string input from the user
        String input = scanner.nextLine();
        S = input.toCharArray();

        // Iterate through each character in the string until the null terminator is reached
        for (int i = 0; i < S.length; i++) {
            // Check if the current character is 'A' and the next character is 'C'
            if (S[i] == 'A' && i + 1 < S.length && S[i + 1] == 'C') {
                // If the condition is met, print "Yes" and exit the program
                System.out.println("Yes");
                return;
            }
        }

        // If the loop completes without finding "AC", print "No"
        System.out.println("No");
    }
}
// <END-OF-CODE>
