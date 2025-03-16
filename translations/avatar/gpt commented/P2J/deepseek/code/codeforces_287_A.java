import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<char[]> t = new ArrayList<>();

        // Read 4 lines of input and store each line as a char array in the list 't'
        for (int i = 0; i < 4; i++) {
            String line = scanner.nextLine();
            t.add(line.toCharArray());
        }

        // Initialize counters for black and white cells
        int black = 0;
        int white = 0;
        // Initialize a flag to indicate if the grid is correct
        boolean correct = false;

        // Iterate through the 3x3 grid (the first 3 rows and columns)
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                // Count the number of black cells ('#') in the 2x2 block
                if (t.get(i)[j] == '#') {
                    black++;
                } else {
                    white++;
                }

                // Check the right cell in the 2x2 block
                if (t.get(i)[j + 1] == '#') {
                    black++;
                } else {
                    white++;
                }

                // Check the bottom cell in the 2x2 block
                if (t.get(i + 1)[j] == '#') {
                    black++;
                } else {
                    white++;
                }

                // Check the bottom right cell in the 2x2 block
                if (t.get(i + 1)[j + 1] == '#') {
                    black++;
                } else {
                    white++;
                }

                // Check if the current 2x2 block is valid (all black or all white)
                if (black == 0 || black == 3 || white == 0 || white == 3 || white == 4 || black == 4) {
                    correct = true; // Mark as correct if the condition is met
                    break;
                }

                // Reset counters for the next 2x2 block
                black = 0;
                white = 0;
            }
            if (correct) {
                break;
            }
        }

        // Output the result based on whether a correct block was found
        if (correct) {
            System.out.println("YES"); // Print 'YES' if a valid block was found
        } else {
            System.out.println("NO");  // Print 'NO' if no valid block was found
        }
    }
}
