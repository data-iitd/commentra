import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the values of n (total positions), m (number of obstacles), s (starting position), and f (finishing position)
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int s = scanner.nextInt();
        int f = scanner.nextInt();

        // Determine the direction of movement based on the starting and finishing positions
        int d = s < f ? 1 : -1;  // Move right if s < f, otherwise move left
        char c = d == 1 ? 'R' : 'L';  // Character representing right or left movement

        // Initialize the result string to store the path taken
        StringBuilder res = new StringBuilder();

        // Initialize the step counter and current position
        int i = 1;
        int j = s;

        // Read the first obstacle's position and range
        int t = 1;
        int l = scanner.nextInt();
        int r = scanner.nextInt();
        int k = 1;  // Counter for the number of obstacles processed

        // Loop until the current position reaches the finishing position
        while (j != f) {
            // Check if we need to read a new obstacle's position and range
            if (i > t && k < m) {
                t = scanner.nextInt();  // Read the next obstacle's position
                l = scanner.nextInt();
                r = scanner.nextInt();
                k++;  // Increment the obstacle counter
            }

            // Check if the current position is at an obstacle
            if (i == t && (j >= l && j <= r || j + d >= l && j + d <= r)) {
                res.append('X');  // Mark the position with 'X' if it's blocked by an obstacle
            } else {
                res.append(c);  // Append the direction character to the result
                j += d;  // Move to the next position in the determined direction
            }

            i++;  // Increment the step counter
        }

        // Print the resulting path taken
        System.out.println(res.toString());
    }
}
