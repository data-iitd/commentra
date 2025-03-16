import java.io.BufferedWriter; 
import java.io.IOException; 
import java.io.OutputStreamWriter; 
import java.util.Scanner; 

public class Main { 
    public static void main(String[] args) throws IOException { 
        // Create a Scanner object for input and a BufferedWriter for output
        Scanner sc = new Scanner(System.in); 
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out)); 
        
        // Read the dimensions of the grid and the parameters A and B
        int H = sc.nextInt(); // Height of the grid
        int W = sc.nextInt(); // Width of the grid
        int A = sc.nextInt(); // Parameter A
        int B = sc.nextInt(); // Parameter B
        
        // Check if the grid can accommodate the required number of 0s and 1s
        if (W < 2 * A || H < 2 * B) { 
            System.out.println(-1); // Print -1 if the grid is too small
            return; // Exit the program
        } 
        
        // Generate the grid based on the parameters A and B
        for (int i = 0; i < H; i++) { // Iterate over each row
            for (int j = 0; j < W; j++) { // Iterate over each column
                // Determine whether to write '0' or '1' based on the current position
                if ((i < B && j < A) || (i >= B && j >= A)) 
                    bw.write("0"); // Write '0' for specified conditions
                else 
                    bw.write("1"); // Write '1' otherwise
            } 
            bw.newLine(); // Move to the next line after finishing a row
        } 
        
        // Flush the BufferedWriter to ensure all data is written out
        bw.flush(); 
    } 
}
