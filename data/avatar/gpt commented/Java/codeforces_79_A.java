import java.io.BufferedReader; 
import java.io.IOException; 
import java.io.InputStreamReader; 
import java.util.StringTokenizer; 

public class Main { 

    // Method to check if the required resources can be taken
    public static boolean canTake(int xNeeded, int xAvailable, int yNeeded, int yAvailable) { 
        // Check if the needed x resources are greater than available
        if (xNeeded > xAvailable) return false; 
        // Check if the needed y resources are greater than available
        if (yNeeded > yAvailable) return false; 
        // If both checks pass, return true
        return true; 
    } 

    public static void main(String[] args) throws IOException { 
        // Initialize BufferedReader to read input
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        // Tokenize the input line to extract x and y values
        StringTokenizer st = new StringTokenizer(br.readLine()); 
        int x = Integer.parseInt(st.nextToken()); // Parse x value
        int y = Integer.parseInt(st.nextToken()); // Parse y value
        int turn = 0; // Initialize turn counter

        // Infinite loop to alternate turns between two players
        while (true) { 
            // Check if it's the first player's turn (even turn number)
            if (turn % 2 == 0) { 
                // Try to take resources according to the defined rules
                if (canTake(2, x, 2, y)) { 
                    x -= 2; // Deduct resources for the first option
                    y -= 2; 
                } else if (canTake(1, x, 12, y)) { 
                    x -= 1; // Deduct resources for the second option
                    y -= 12; 
                } else if (canTake(0, x, 22, y)) { 
                    y -= 22; // Deduct resources for the third option
                } else { 
                    // If no options are available, first player loses
                    System.out.println("Hanako"); 
                    return; 
                } 
            } else { 
                // Check if it's the second player's turn (odd turn number)
                if (canTake(0, x, 22, y)) { 
                    y -= 22; // Deduct resources for the first option
                } else if (canTake(1, x, 12, y)) { 
                    x -= 1; // Deduct resources for the second option
                    y -= 12; 
                } else if (canTake(2, x, 2, y)) { 
                    x -= 2; // Deduct resources for the third option
                    y -= 2; 
                } else { 
                    // If no options are available, second player loses
                    System.out.println("Ciel"); 
                    return; 
                } 
            } 
            turn++; // Increment turn counter for the next iteration
        } 
    } 
}
