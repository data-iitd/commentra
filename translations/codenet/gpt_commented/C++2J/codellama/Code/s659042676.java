import java.util.Scanner; // Import the Scanner class for reading input from the command line

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for reading input from the command line

        int a = scanner.nextInt(); // Read the first integer value from the command line
        int b = scanner.nextInt(); // Read the second integer value from the command line

        System.out.println(6 - a - b); // Calculate and output the result of the expression (6 - a - b)
    }
}

