import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of princesses, dragons, time, and other parameters from user input
        int princess = scanner.nextInt();
        int dragon = scanner.nextInt();
        int t = scanner.nextInt();
        int f = scanner.nextInt();
        int c = scanner.nextInt();

        // If the number of dragons is less than or equal to the number of princesses, print 0 and exit
        if (dragon <= princess) {
            System.out.println(0);
            return;
        }

        // Initialize the result counter for the number of iterations
        int result = 0;

        // Calculate the initial position based on the time and number of princesses
        double position = t * princess;

        // Update the position based on the ratio of princesses to dragons
        position += princess * position / (dragon - princess);

        // Loop until the position is less than the target value 'c'
        while (position < c) {
            // Increment the result counter for each iteration
            result++;

            // Update the position based on the current number of princesses and dragons
            position += princess * position / dragon;

            // Add the effect of the time factor 'f' to the position
            position += princess * f;

            // Recalculate the position based on the updated values
            position += princess * position / (dragon - princess);
        }

        // Print the final result which is the number of iterations needed
        System.out.println(result);
    }
}
