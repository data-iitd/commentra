import java.io.BufferedReader; // Importing BufferedReader for input operations
import java.io.IOException; // Importing IOException for exception handling
import java.io.InputStreamReader; // Importing InputStreamReader for reading input stream
import java.util.StringTokenizer; // Importing StringTokenizer for tokenizing input strings

public class Main {
    // The canTake method checks if the resources are sufficient to meet the requirements
    public static boolean canTake(int xNeeded, int xAvailable, int yNeeded, int yAvailable) {
        if (xNeeded > xAvailable) return false; // Check if xNeeded is more than xAvailable
        if (yNeeded > yAvailable) return false; // Check if yNeeded is more than yAvailable
        return true; // Return true if both conditions are satisfied
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // Creating BufferedReader object to read input
        StringTokenizer st = new StringTokenizer(br.readLine()); // Tokenizing the input line
        int x = Integer.parseInt(st.nextToken()); // Parsing the first token as an integer for x
        int y = Integer.parseInt(st.nextToken()); // Parsing the second token as an integer for y
        int turn = 0; // Initializing the turn counter

        // The main loop where the game alternates between two players based on the turn counter
        while (true) {
            if (turn % 2 == 0) { // Check if it's Hanako's turn (even turn)
                // Hanako's turn actions: Attempt to take resources in the given order
                if (canTake(2, x, 2, y)) { // Attempt to take 2 from both x and y
                    x -= 2;
                    y -= 2;
                } else if (canTake(1, x, 12, y)) { // Attempt to take 1 from x and 12 from y
                    x -= 1;
                    y -= 12;
                } else if (canTake(0, x, 22, y)) { // Attempt to take 22 from y
                    y -= 22;
                } else { // If no resources can be taken, Hanako loses
                    System.out.println("Hanako");
                    return;
                }
            } else { // It's Ciel's turn (odd turn)
                // Ciel's turn actions: Attempt to take resources in the given order
                if (canTake(0, x, 22, y)) { // Attempt to take 22 from y
                    y -= 22;
                } else if (canTake(1, x, 12, y)) { // Attempt to take 1 from x and 12 from y
                    x -= 1;
                    y -= 12;
                } else if (canTake(2, x, 2, y)) { // Attempt to take 2 from both x and y
                    x -= 2;
                    y -= 2;
                } else { // If no resources can be taken, Ciel loses
                    System.out.println("Ciel");
                    return;
                }
            }
            turn++; // Increment the turn counter
        }
    }
}
