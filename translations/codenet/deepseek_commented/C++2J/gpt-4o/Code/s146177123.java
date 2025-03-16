import java.util.Scanner;

public class Main {
    // Array to represent the segments of the digits 0-9
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
        int n, t;
        boolean[] st = new boolean[7];

        while ((n = scanner.nextInt()) != -1) { // Read the number of digits and check if it's not -1
            // Initialize the state array to represent the current display state
            for (int i = 0; i < 7; i++) {
                st[i] = false;
            }
            for (int i = 0; i < n; i++) {
                t = scanner.nextInt(); // Read the next digit
                StringBuilder ans = new StringBuilder(); // StringBuilder to store the current display state
                for (int j = 0; j < 7; j++) {
                    // Calculate the current segment state and store it in the answer
                    ans.append(st[j] ^ seg[t][j] ? '1' : '0');
                    // Update the state array with the current segment state
                    st[j] = seg[t][j];
                }
                // Output the current display state
                System.out.println(ans);
            }
        }
        scanner.close();
    }
}
// <END-OF-CODE>
