import java.util.Scanner;

public class PathFinder {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the values of n (total positions), m (number of obstacles), s (starting position), and f (finishing position)
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int s = scanner.nextInt();
        int f = scanner.nextInt();

        // Determine the direction of movement based on the starting and finishing positions
        int d;
        char c;
        if (s < f) {
            d = 1;  // Move right
            c = 'R';  // Character representing right movement
        } else {
            d = -1;  // Move left
            c = 'L';  // Character representing left movement
        }

        // Initialize the result string to store the path taken
        StringBuilder res = new StringBuilder();

        // Initialize the step counter and current position
        int i = 1;
        int j = s;

        // Read the first obstacle's position and range
        int t = scanner.nextInt();
        int l = scanner.nextInt();
        int r = scanner.nextInt();
        int k = 1;  // Counter for the number of obstacles processed

        // Loop until the current position reaches the finishing position
        while (j != f) {
            // Check if we need to read a new obstacle's position and range
            if (i > t && k < m) {
                t = scanner.nextInt();  // Read the next obstacle's position
                l = scanner.nextInt();  // Read the left range of the obstacle
                r = scanner.nextInt();  // Read the right range of the obstacle
                k++;  // Increment the obstacle counter
            }

            // Check if the current position is at an obstacle
            if (i == t && (l <= j && j <= r || l <= j + d && j + d <= r)) {
                res.append('X');  // Mark the position with 'X' if it's blocked by an obstacle
            } else {
                res.append(c);  // Append the direction character to the result
                j += d;  // Move to the next position in the determined direction
            }

            i++;  // Increment the step counter
        }

        // Print the resulting path taken
        System.out.println(res.toString());

        scanner.close();
    }
}
// <END-OF-CODE>
