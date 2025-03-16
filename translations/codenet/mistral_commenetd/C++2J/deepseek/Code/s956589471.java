import java.util.Scanner; // Import the Scanner class for reading input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input

        // Read the values of these variables from the standard input using the Scanner
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        int d = scanner.nextInt();
        int e = scanner.nextInt();
        int k = scanner.nextInt();

        // Perform a simple condition check using the relational operator <=
        if (e - a <= k) {
            System.out.println("Yay!"); // If the condition is true, print "Yay!" to the standard output
        } else {
            System.out.println(":("); // If the condition is false, print ":" and a sad face "(" to the standard output
        }

        scanner.close(); // Close the Scanner object to free up resources
    }
}
