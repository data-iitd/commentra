import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt(); // Read the first integer value from the user
        int b = scanner.nextInt(); // Read the second integer value from the user
        int result; // Declare variable 'result' to store the result of the computation

        if (a > b) { // Check if 'a' is greater than 'b'
            result = 2 * a - 1; // If true, assign the value '2 * a - 1' to 'result'
        } else if (a == b) { // Check if 'a' is equal to 'b'
            result = 2 * a; // If true, assign the value '2 * a' to 'result'
        } else { // If 'a' is less than 'b'
            result = 2 * b - 1; // Assign the value '2 * b - 1' to 'result'
        }

        System.out.println(result); // Print the value of 'result' to the console
    }
}
