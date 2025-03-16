// Read input from the standard input (user input)
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();

        // Check if both 'A' and 'B' are present in the input string
        // If both are found, set result to "Yes", otherwise set it to "No"
        String result = "Yes";
        if (!s.contains("A") ||!s.contains("B")) {
            result = "No";
        }

        // Print the result indicating whether both 'A' and 'B' were found
        System.out.println(result);
    }
}
