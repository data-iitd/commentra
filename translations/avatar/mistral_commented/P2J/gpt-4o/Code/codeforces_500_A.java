import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Creating a Scanner object to take input
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
        int currentCell = 0;

        // Main logic of the program starts here
        while (currentCell < t) {
            // Incrementing the current cell position by the jump from the previous cell
            currentCell += s[currentCell];

            // Checking if the current cell position is equal to the target position
            if (currentCell == t) {
                // If yes, then print "YES" and exit the program
                System.out.println("YES");
                return;
            }
        }

        // If the loop terminates without finding the target position, then print "NO"
        System.out.println("NO");
    }
}
// <END-OF-CODE>
