import java.util.Scanner;

public class Main {
    // Segment representation for digits 0-9
    static boolean[][] seg = {
        {false, true, true, true, true, true, true}, // 0
        {false, false, false, false, true, true, false}, // 1
        {true, false, true, true, false, true, true}, // 2
        {true, false, false, true, true, true, true}, // 3
        {true, true, false, false, true, true, false}, // 4
        {true, true, false, true, true, false, true}, // 5
        {true, true, true, true, true, false, true}, // 6
        {false, true, false, false, true, true, true}, // 7
        {true, true, true, true, true, true, true}, // 8
        {true, true, false, true, true, true, true}  // 9
    };

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, t; // Declare variables for input and digit
        boolean[] st = new boolean[7]; // Array to store the state of segments

        // Read input until a negative number is encountered
        while ((n = scanner.nextInt()) >= 0) {
            for (int i = 0; i < 7; i++) {
                st[i] = false; // Initialize segment states to false
            }

            // Process each digit input
            for (int i = 0; i < n; i++) {
                t = scanner.nextInt(); // Read the digit
                StringBuilder ans = new StringBuilder("0000000"); // Initialize answer array to store segment states

                // Determine the segment states based on the input digit
                for (int j = 0; j < 7; j++) {
                    // Calculate the current segment state and store it in ans
                    ans.setCharAt(j, (st[j] ^ seg[t][j]) ? '1' : '0');
                    st[j] = seg[t][j]; // Update the current segment state
                }
                System.out.println(ans); // Output the segment states for the current digit
            }
        }
        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
