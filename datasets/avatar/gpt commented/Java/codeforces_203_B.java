import java.util.Scanner; // Import the Scanner class for user input

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in); // Create a Scanner object to read input from the user
        
        // Read the dimensions of the grid (N) and the number of moves (M)
        int N = in.nextInt();
        int M = in.nextInt();
        
        // Initialize a 2D array to keep track of the black cells, with padding to avoid boundary checks
        int[][] black = new int[N + 2][N + 2];
        
        // Loop through each move
        for (int m = 1; m <= M; m++) {
            // Read the coordinates of the current move
            int x = in.nextInt();
            int y = in.nextInt();
            
            // Increment the count of black cells in the surrounding 3x3 area
            for (int xx = x - 1; xx <= x + 1; xx++) {
                for (int yy = y - 1; yy <= y + 1; yy++) {
                    // Increment the count for the current cell
                    if (++black[xx][yy] == 9) { // Check if the count reaches 9
                        System.out.println(m); // Print the move number where the condition is met
                        return; // Exit the program
                    }
                }
            }
        }
        
        // If no cell reached the count of 9 after all moves, print -1
        System.out.println("-1");
    }
}
