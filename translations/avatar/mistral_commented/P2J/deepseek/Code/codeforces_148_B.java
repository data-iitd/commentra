import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read in five integers from the standard input
        int princess = scanner.nextInt();
        int dragon = scanner.nextInt();
        int t = scanner.nextInt();
        int f = scanner.nextInt();
        int c = scanner.nextInt();

        // Check if the dragon is smaller than or equal to the princess
        // If so, print 0 and exit the program
        if (dragon <= princess) {
            System.out.println(0);
            return;
        }

        // Initialize a variable result to 0
        int result = 0;

        // Calculate an initial position based on t and princess
        double position = t * princess;

        // Enter a while loop that continues as long as the position is less than c
        while (position < c) {
            // Increment result by 1
            result += 1;

            // Update the position by adding the given terms
            position += princess * position / dragon;
            position += princess * f;
            position += princess * position / (dragon - princess);
        }

        // Once the loop terminates, print the final value of result
        System.out.println(result);
    }
}
