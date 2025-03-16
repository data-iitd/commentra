import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<List<String>> t = new ArrayList<>(); // Initialize an empty list 't' to store the input strings

        for (int i = 0; i < 4; i++) { // Loop through 4 iterations to get input strings from user
            String input = scanner.nextLine(); // Read input string
            List<String> l = new ArrayList<>(); // Create a new list for the current row
            for (char c : input.toCharArray()) {
                l.add(String.valueOf(c)); // Convert input string to list of strings
            }
            t.add(l); // Append the list to list 't'
        }

        int black = 0; // Initialize black and white counters to 0
        int white = 0;
        int correct = 0;

        for (int i = 0; i < 3; i++) { // Loop through the first 3 rows of the 4x4 grid represented by list 't'
            for (int j = 0; j < 3; j++) { // Loop through the first 3 columns of the current row
                if (t.get(i).get(j).equals("#")) { // If current cell contains '#', increment 'black' counter
                    black++;
                } else { // If current cell contains '.', increment 'white' counter
                    white++;
                }

                // Check the neighboring cells and increment 'black' or 'white' counter accordingly
                if (t.get(i).get(j + 1).equals("#")) {
                    black++;
                } else {
                    white++;
                }

                if (t.get(i + 1).get(j).equals("#")) {
                    black++;
                } else {
                    white++;
                }

                if (t.get(i + 1).get(j + 1).equals("#")) {
                    black++;
                } else {
                    white++;
                }

                // Check the current cell and its neighbors for winning conditions
                if (black == 0 || black == 3 || white == 0 || white == 3 || white == 4 || black == 4) {
                    correct = 1; // If a winning condition is met, set 'correct' to 1 and break out of the loop
                    break;
                }

                // Reset black and white counters for the next iteration of the inner loop
                black = 0;
                white = 0;
            }
            if (correct == 1) { // Break outer loop if correct is set to 1
                break;
            }
        }

        if (correct == 1) { // If 'correct' is set to 1, print 'YES'
            System.out.println("YES");
        } else { // If 'correct' is not set to 1, print 'NO'
            System.out.println("NO");
        }

        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
