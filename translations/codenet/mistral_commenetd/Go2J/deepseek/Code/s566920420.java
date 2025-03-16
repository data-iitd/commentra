import java.util.Scanner; // Import the Scanner class for reading input

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the standard input stream
        Scanner scanner = new Scanner(System.in);

        // Declare a variable named "a" of type int
        int a;

        // Read a value of type int from the standard input and store it in the variable "a"
        a = scanner.nextInt();

        // Calculate the result of the expression "a + a*a + a*a*a"
        int result = a + a*a + a*a*a;

        // Print the result to the standard output
        System.out.println(result);

        // End of code
    }
}
