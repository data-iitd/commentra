import java.util.Scanner; // Import the Scanner class for input operations

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input
        int a = scanner.nextInt(); // Read the value of a from the standard input
        int b = scanner.nextInt(); // Read the value of b from the standard input

        // Check if both a and b are less than or equal to 8
        if (a <= 8 && b <= 8) {
            System.out.println("Yay!"); // If the condition is true, print "Yay!" to the standard output
        } else {
            System.out.println(":("); // If the condition is false, print ":(" to the standard output
        }

        // End the main function and return 0 to the operating system
    }
}
