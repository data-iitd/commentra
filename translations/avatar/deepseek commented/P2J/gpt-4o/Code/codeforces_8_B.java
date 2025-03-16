import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class MovementTracker {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String recordOfMovements = scanner.nextLine();  // Take input for the movements of a character
        int x = 0, y = 0;  // Initialize the starting position (x, y) to (0, 0)
        
        // Define a map that maps each direction to its coordinate changes
        Map<Character, int[]> dMovement = new HashMap<>();
        dMovement.put('L', new int[]{0, -1});
        dMovement.put('R', new int[]{0, 1});
        dMovement.put('U', new int[]{1, 0});
        dMovement.put('D', new int[]{-1, 0});
        
        // Initialize a map to keep track of visited positions
        Map<String, String> d = new HashMap<>();
        d.put(x + "," + y, "");  // Store the initial position
        
        boolean bug = false;  // Set a flag bug to False

        for (char move : recordOfMovements.toCharArray()) {  // Iterate over each movement in the input
            String temp = x + "," + y;  // Store the current position in a temporary variable
            x += dMovement.get(move)[0];  // Update the x-coordinate based on the direction
            y += dMovement.get(move)[1];  // Update the y-coordinate based on the direction
            
            if (!d.containsKey(x + "," + y)) {  // Check if the new position has been visited before
                for (char step : dMovement.keySet()) {  // Check the surrounding positions
                    int newX = x + dMovement.get(step)[0];
                    int newY = y + dMovement.get(step)[1];
                    if (newX != x || newY != y) {
                        if (d.containsKey(newX + "," + newY)) {
                            bug = true;  // Set the bug flag to True if a bug is detected
                            break;  // Break out of the loop if a bug is detected
                        }
                    }
                }
            } else {
                bug = true;  // Set the bug flag to True if the new position has been visited before
            }
            
            if (bug) {  // Check if a bug was detected
                break;  // Break out of the loop if a bug was detected
            }
            
            d.put(x + "," + y, "");  // Add the new position to the map d
        }

        if (bug) {  // Check if a bug was detected
            System.out.println("BUG");  // Print 'BUG' if a bug was detected
        } else {
            System.out.println("OK");  // Print 'OK' if no bug was detected
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
