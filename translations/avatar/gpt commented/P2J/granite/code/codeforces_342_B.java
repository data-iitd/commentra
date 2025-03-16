
import java.util.Scanner;

public class codeforces_342_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();  // Total positions
        int m = scanner.nextInt();  // Number of obstacles
        int s = scanner.nextInt();  // Starting position
        int f = scanner.nextInt();  // Finishing position

        int d = s < f? 1 : -1;  // Direction of movement
        char c = s < f? 'R' : 'L';  // Character representing movement direction

        StringBuilder res = new StringBuilder();  // Result string to store the path taken
        int i = 1;  // Step counter
        int j = s;  // Current position

        int t = scanner.nextInt();  // Obstacle position
        int l = scanner.nextInt();  // Obstacle left range
        int r = scanner.nextInt();  // Obstacle right range
        int k = 1;  // Counter for the number of obstacles processed

        while (j!= f) {
            if (i > t && k < m) {
                t = scanner.nextInt();  // Read the next obstacle's position
                l = scanner.nextInt();  // Read the next obstacle's left range
                r = scanner.nextInt();  // Read the next obstacle's right range
                k++;  // Increment the obstacle counter
            }

            if (i == t && (l <= j && j <= r || l <= j + d && j + d <= r)) {
                res.append('X');  // Mark the position with 'X' if it's blocked by an obstacle
            } else {
                res.append(c);  // Append the direction character to the result
                j += d;  // Move to the next position in the determined direction
            }

            i++;  // Increment the step counter
        }

        System.out.println(res.toString());  // Print the resulting path taken
    }
}

