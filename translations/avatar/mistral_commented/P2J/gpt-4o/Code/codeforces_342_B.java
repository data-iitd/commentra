import java.util.Scanner;

public class TrackMovement {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the input values: n (number of test cases), m (number of tracks), s (starting position), and f (final position)
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int s = scanner.nextInt();
        int f = scanner.nextInt();

        // Check if the starting position is less than the final position
        int d;
        char c;
        if (s < f) {
            d = 1;
            c = 'R';
        } else {
            d = -1;
            c = 'L';
        }

        // Initialize an empty StringBuilder to store the output
        StringBuilder res = new StringBuilder();

        // Initialize variables i and j with initial values
        int i = 1;
        int j = s;

        // Read the next input: three integers t, l, and r representing the length, left end, and right end of a track
        int t = scanner.nextInt();
        int l = scanner.nextInt();
        int r = scanner.nextInt();

        // Initialize a variable k to keep track of the number of tracks
        int k = 1;

        // While the current position j is not equal to the final position f
        while (j != f) {
            // If we have read all the tracks or the current position i is not in the current track
            if (i > t && k < m) {
                // Read the next input: three integers t, l, and r representing the length, left end, and right end of the next track
                t = scanner.nextInt();
                l = scanner.nextInt();
                r = scanner.nextInt();
                // Increment the number of tracks
                k++;
            }

            // If the current position i is in the current track (either it is the same track or it overlaps with the current track)
            if (i == t && (l <= j && j <= r || l <= j + d && j + d <= r)) {
                // Append 'X' to the output string
                res.append('X');
            } else {
                // Append the corresponding direction character 'R' or 'L' to the output string
                res.append(c);
                // Update the current position j based on the direction
                j += d;
            }
            // Increment the current position i
            i++;
        }

        // Print the output string
        System.out.println(res.toString());

        scanner.close();
    }
}
// <END-OF-CODE>
