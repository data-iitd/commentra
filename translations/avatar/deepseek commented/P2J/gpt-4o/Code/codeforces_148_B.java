import java.util.Scanner;

public class PrincessDragon {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input the number of princess's power
        int princess = scanner.nextInt();
        // Input the number of dragon's power
        int dragon = scanner.nextInt();
        // Input the initial time
        int t = scanner.nextInt();
        // Input the time increment
        int f = scanner.nextInt();
        // Input the target power level
        int c = scanner.nextInt();

        // Check if the dragon's power is less than or equal to the princess's power
        if (dragon <= princess) {
            System.out.println(0); // If dragon is not stronger, no attacks needed
            return; // Exit the program
        }

        int result = 0; // Initialize the result counter
        double position = t * princess; // Calculate the initial position based on time and princess's power
        position += princess * position / (dragon - princess); // Adjust the position based on the given formula

        // Enter a while loop that continues until the position is greater than or equal to the target power level
        while (position < c) {
            result++; // Increment the result counter
            position += princess * position / dragon; // Update the position based on the dragon's power
            position += princess * f; // Add the time increment to the position
            position += princess * position / (dragon - princess); // Adjust the position based on the given formula
        }

        System.out.println(result); // Print the number of attacks needed
    }
}
// <END-OF-CODE>
