import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare two integer variables to store the number of sheep and wolves
        int sheep;
        int wolf;

        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Read two integers from the standard input and store them in the sheep and wolf variables
        sheep = scanner.nextInt();
        wolf = scanner.nextInt();

        // Check if the number of wolves is greater than or equal to the number of sheep
        if (wolf >= sheep) {
            // If the condition is true, print the message "unsafe" to the standard output
            System.out.println("unsafe");
        } else {
            // If the condition is false, print the message "safe" to the standard output
            System.out.println("safe");
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
