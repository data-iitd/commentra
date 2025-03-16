import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Taking input for number of test cases and time limit
        int n = scanner.nextInt();
        int t = scanner.nextInt();

        // Initializing an array to store the jumps
        int[] s = new int[n];
        for (int i = 0; i < n; i++) {
            s[i] = scanner.nextInt();
        }

        // Initializing the current cell position to 0
        int current_cell = 0;

        // Main logic of the program starts here
        while (current_cell < t) {
            // Incrementing the current cell position by the jump from the previous cell
            current_cell += s[current_cell];

            // Checking if the current cell position is equal to the target position
            if (current_cell == t) {
                // If yes, then print "YES" and exit the program
                System.out.println("YES");
                return;
            }

            // If not, then continue to the next iteration
        }

        // If the loop terminates without finding the target position, then print "NO"
        System.out.println("NO");
    }
}
