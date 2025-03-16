
import java.util.Scanner; // Import the Scanner class for reading input

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in); // Create a Scanner object to read input
        int N = in.nextInt(); // Read the first integer input, which is the size of the grid
        int M = in.nextInt(); // Read the second integer input, which is the number of operations

        // Initialize a 2D array 'black' with dimensions (N+2) x (N+2)
        int[][] black = new int[N + 2][N + 2];

        // Loop through M operations
        for (int m = 1; m <= M; m++) {
            int x = in.nextInt(); // Read the x-coordinate of the current operation
            int y = in.nextInt(); // Read the y-coordinate of the current operation

            // Increment the elements in the 'black' array within the 3x3 neighborhood of (x, y)
            for (int xx = x - 1; xx <= x + 1; xx++) {
                for (int yy = y - 1; yy <= y + 1; yy++) {
                    if (++black[xx][yy] == 9) { // Increment the element and check if it reaches 9
                        System.out.println(m); // Print the current operation number
                        return; // Exit the program
                    }
                }
            }
        }

        // If no element reaches 9 after all operations, print -1
        System.out.println("-1");
    }
}

