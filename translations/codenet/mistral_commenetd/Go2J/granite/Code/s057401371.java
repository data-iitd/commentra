
// Importing required packages
import java.util.Scanner;

public class s057401371{
    public static void main(String[] args) {
        // Initializing a scanner for reading from standard input
        Scanner sc = new Scanner(System.in);

        // Reading the first line from standard input and storing it in the string's'
        String s = sc.nextLine();

        // Declaring and initializing a variable 'd' with the value of 'a' - 'A'
        int d = 'a' - 'A';

        // Iterating through each character 'r' in the string's'
        for (char r : s.toCharArray()) {
            // Declaring and initializing a variable 'rr' with the value of 'r'
            char rr = r;

            // Checking if the current character 'r' is an uppercase letter
            if ('A' <= r && r <= 'Z') {
                // If yes, adding the value of 'd' to 'r' and storing it in 'rr'
                rr = (char) (r + d);
            } else if ('a' <= r && r <= 'z') {
                // If no, subtracting the value of 'd' from 'r' and storing it in 'rr'
                rr = (char) (r - d);
            }

            // Printing the transformed character 'rr' to the standard output
            System.out.print(rr);
        }

        // Printing a newline character after the transformation is complete
        System.out.println();
    }
}

// End of the code