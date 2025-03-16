import java.io.BufferedWriter; // Importing BufferedWriter for efficient output writing
import java.io.IOException; // Importing IOException for exception handling
import java.io.OutputStreamWriter; // Importing OutputStreamWriter for character stream handling
import java.util.Scanner; // Importing Scanner for reading input

public class Main {
    public static void main(String[] args) throws IOException { // Main method is the entry point of the program
        Scanner sc = new Scanner(System.in); // Initializing Scanner to read input from the console
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out)); // Initializing BufferedWriter to write output to the console

        int H = sc.nextInt(); // Reading the height of the matrix
        int W = sc.nextInt(); // Reading the width of the matrix
        int A = sc.nextInt(); // Reading the value of A
        int B = sc.nextInt(); // Reading the value of B

        // Checking if the matrix dimensions are suitable for the given values of A and B
        if (W < 2 * A || H < 2 * B) {
            System.out.println(-1); // Printing -1 if the matrix dimensions are not suitable
            return; // Exiting the program
        }

        // Nested loops to generate the matrix
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                // Assigning 0 or 1 based on the conditions specified
                if ((i < B && j < A) || (i >= B) && (j >= A)) {
                    bw.write("0"); // Writing 0 to the buffer
                } else {
                    bw.write("1"); // Writing 1 to the buffer
                }
            }
            bw.newLine(); // Moving to the next line after each row is written
        }

        bw.flush(); // Flushing the buffer to ensure all data is written to the console
    }
}
