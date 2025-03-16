import java.util.*;

public class SevenSegment {
    // Segment representation for digits 0-9
    private static final boolean[][] seg = {
        {0, 1, 1, 1, 1, 1, 1}, // 0
        {0, 0, 0, 0, 1, 1, 0}, // 1
        {1, 0, 1, 1, 0, 1, 1}, // 2
        {1, 0, 0, 1, 1, 1, 1}, // 3
        {1, 1, 0, 0, 1, 1, 0}, // 4
        {1, 1, 0, 1, 1, 0, 1}, // 5
        {1, 1, 1, 1, 1, 0, 1}, // 6
        {0, 1, 0, 0, 1, 1, 1}, // 7
        {1, 1, 1, 1, 1, 1, 1}, // 8
        {1, 1, 0, 1, 1, 1, 1}  // 9
    };

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, t; // Declare variables for input and digit
        boolean[] st = new boolean[7]; // Array to store the state of segments

        // Read input until a negative number is encountered
        while ((n = scanner.nextInt()) >= 0) {
            Arrays.fill(st, false); // Initialize segment states to false

            // Process each digit input
            for (int i = 0; i < n; i++) {
                t = scanner.nextInt(); // Read the digit
                char[] ans = new char[7]; // Array to store segment states
                Arrays.fill(ans, '0'); // Initialize answer array to '0'

                // Determine the segment states based on the input digit
                for (int j = 0; j < 7; j++) {
                    // Calculate the current segment state and store it in ans
                    ans[j] = st[j] ^ seg[t][j] ? '1' : '0';
                    st[j] = seg[t][j]; // Update the current segment state
                }
                System.out.println(new String(ans)); // Output the segment states for the current digit
            }
        }
    }
}
