import java.util.Scanner;

public class SegmentTree {
    static boolean[][] seg = {
        {false, true, true, true, true, true, true},
        {false, false, false, false, true, true, false},
        {true, false, true, true, false, true, true},
        {true, false, false, true, true, true, true},
        {true, true, false, false, true, true, false},
        {true, true, false, true, true, false, true},
        {true, true, true, true, true, false, true},
        {false, true, false, false, true, true, true},
        {true, true, true, true, true, true, true},
        {true, true, false, true, true, true, true}
    };

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, t; // Variables to store the number of test cases and the current test case
        boolean[] st = new boolean[7]; // A boolean array to store the current segment tree state

        while ((n = scanner.nextInt()) != -1) { // Reading the number of test cases and processing them while there are still test cases to be processed
            for (int i = 0; i < 7; i++) {
                st[i] = false; // Initializing the segment tree state to all false
            }
            for (int i = 0; i < n; i++) { // Processing each test case
                t = scanner.nextInt(); // Reading the current test case
                char[] ans = new char[7]; // Initializing an array to store the answer as a string of '0's and '1's
                for (int j = 0; j < 7; j++) { // Iterating through each bit position in the segment tree
                    ans[j] = (st[j] ^ seg[t][j]) ? '1' : '0'; // Updating the answer based on the current segment tree state and the current test case
                    st[j] = seg[t][j]; // Updating the segment tree state for the current bit position
                }
                System.out.println(new String(ans)); // Printing the answer for the current test case
            }
        }

        scanner.close(); // Closing the scanner
    }
}
// <END-OF-CODE>
