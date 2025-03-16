import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Create a Scanner object to read input from the standard input stream
        Scanner sc = new Scanner(System.in);
        
        // Read the dimensions of the grid (height H and width W)
        int H = sc.nextInt();
        int W = sc.nextInt();
        
        // Consume the newline character left in the input buffer
        sc.nextLine();
        
        // Initialize a 2D character array to store the grid's characters
        char[][] S = new char[H][W];
        
        // Read each line of the grid and store it in the 2D array S
        for (int i = 0; i < H; i++) {
            String text = sc.nextLine();
            for (int j = 0; j < W; j++) {
                S[i][j] = text.charAt(j);
            }
        }
        
        // Close the Scanner object to free up resources
        sc.close();

        // Iterate over each cell in the grid
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                // If the cell is a dot (.), count the number of adjacent hashes (#)
                if (S[i][j] == '.') {
                    int count = 0;
                    for (int a = -1; a <= 1; a++) {
                        if (i + a < 0 || H <= i + a) {
                            continue;
                        }
                        for (int b = -1; b <= 1; b++) {
                            if (j + b < 0 || W <= j + b) {
                                continue;
                            }
                            if ( S[i + a][j + b] == '#') {
                                count++;
                            }
                        }
                    }
                    // Update the cell with the count of adjacent hashes
                    S[i][j] = (char)(count+48);
                }
                // Print the updated cell to the standard output
                System.out.printf("%c", S[i][j]);
            }
            // Print a newline character after each row
            System.out.printf("\n");
        }
    }
}
