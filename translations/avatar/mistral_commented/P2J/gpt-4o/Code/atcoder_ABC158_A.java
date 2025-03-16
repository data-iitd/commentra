import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Read a line from the standard input
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();

        // Initialize the variable result with "Yes" if "A" and "B" are present in s, otherwise initialize it with "No"
        String result = (s.contains("A") && s.contains("B")) ? "Yes" : "No";

        // Print the value of the variable result
        System.out.println(result);
    }
}
// <END-OF-CODE>
