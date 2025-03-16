import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Read input from the standard input (user input)
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();

        // Check if both 'A' and 'B' are present in the input string
        // If both are found, set result to "Yes", otherwise set it to "No"
        String result = (s.contains("A") && s.contains("B")) ? "Yes" : "No";

        // Print the result indicating whether both 'A' and 'B' were found
        System.out.println(result);
        
        scanner.close();
    }
}
// <END-OF-CODE>
