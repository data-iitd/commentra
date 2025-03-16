
import java.util.Scanner;

public class s681783549{
    public static void main(String[] args) {
        // Declare an integer variable for iteration and a character array to store input
        int i;
        char S[] = new char[6];

        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Read a string input from the user
        scanner.nextLine().getChars(0, 6, S, 0);

        // Iterate through each character in the string until the null terminator is reached
        for(i = 0; S[i]!= '\0'; i++) {
            // Check if the current character is 'A' and the next character is 'C'
            if(S[i] == 'A' && S[i + 1] == 'C') {
                // If the condition is met, print "Yes" and exit the program
                System.out.println("Yes");
                return;
            }
        }

        // If the loop completes without finding "AC", print "No"
        System.out.println("No");
    }
}
