import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<char[]> t = new ArrayList<>();  // Initialize an empty list to store the input data.

        // Loop to take input and store it in the list t.
        for (int i = 0; i < 4; i++) {
            char[] l = scanner.nextLine().toCharArray();  // Take input, convert it to a list of characters, and append to t.
            t.add(l);
        }

        int black = 0;  // Initialize the count of black cells to 0.
        int white = 0;  // Initialize the count of white cells to 0.
        int correct = 0;  // Initialize the correct flag to 0.

        // Nested loop to iterate over the 3x3 grid formed by the first 3 rows and columns of t.
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                // Count the number of black and white cells in the current 2x2 subgrid.
                if (t.get(i)[j] == '#') {
                    black++;
                } else {
                    white++;
                }
                if (t.get(i)[j + 1] == '#') {
                    black++;
                } else {
                    white++;
                }
                if (t.get(i + 1)[j] == '#') {
                    black++;
                } else {
                    white++;
                }
                if (t.get(i + 1)[j + 1] == '#') {
                    black++;
                } else {
                    white++;
                }

                // Check if the counts of black and white cells meet any of the specified conditions.
                if (black == 0 || black == 3 || white == 0 || white == 3 || white == 4 || black == 4) {
                    correct = 1;
                    break;  // If conditions are met, set correct to 1 and break out of the loop.
                }

                black = 0;  // Reset the count of black cells.
                white = 0;  // Reset the count of white cells.
            }
            if (correct == 1) {
                break;
            }
        }

        // Print 'YES' if correct is 1, otherwise print 'NO'.
        System.out.println(correct == 1 ? "YES" : "NO");
    }
}
