import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Get two integers from user input, separated by a space
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();

        // Initialize the variable 'hole' to 1
        int hole = 1;

        // Initialize the variable 'i' to 0
        int i = 0;

        // Initialize the variable 'check' to true
        boolean check = true;

        // Loop until the condition is not met
        while (check) {
            // Check if the value of 'hole' is greater than or equal to 'b'
            if (hole >= b) {
                // If the condition is met, set 'check' to false to terminate the loop
                check = false;
            } else {
                // If the condition is not met, update the value of 'hole'
                hole = a * (i + 1) - i;
                // Increment the value of 'i' by 1
                i++;
            }
        }

        // Once the loop terminates, print out the value of 'i' as the result
        System.out.println(i);
    }
}
// <END-OF-CODE>
