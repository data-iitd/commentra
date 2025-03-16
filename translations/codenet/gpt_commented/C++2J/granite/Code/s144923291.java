
import java.util.*;

public class s144923291{
    public static void main(String[] args) {
        // Read height and width of the grid
        Scanner sc = new Scanner(System.in);
        int h = sc.nextInt();
        int w = sc.nextInt();

        // Initialize a temporary character array and the target string
        char[] t = new char[10];
        String s = "snuke";

        // Iterate through the grid to find the target string
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                // Read the current string from input
                t = sc.next().toCharArray();
                // Check if the current string matches the target string
                if (new String(t).equals(s)) {
                    // If found, calculate the position and print it
                    char c = (char) ('A' + j); // Convert column index to character
                    System.out.println(c + (i + 1)); // Output the position in the required format
                    return; // Exit the program after finding the target
                }
            }
        }
    }
}

// Return 0 to indicate successful execution
