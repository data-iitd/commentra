import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class MovementTracker {
    public static void main(String[] args) {
        // Read the input string representing movements
        Scanner scanner = new Scanner(System.in);
        String recordOfMovements = scanner.nextLine();

        // Initialize the starting coordinates (x, y) at (0, 0)
        int x = 0, y = 0;

        // Define the movement directions: Left (L), Right (R), Up (U), Down (D)
        Map<Character, int[]> dMovement = new HashMap<>();
        dMovement.put('L', new int[]{0, -1});
        dMovement.put('R', new int[]{0, 1});
        dMovement.put('U', new int[]{1, 0});
        dMovement.put('D', new int[]{-1, 0});

        // Create a map to track visited coordinates, starting with the initial position
        Map<String, String> visited = new HashMap<>();
        visited.put(x + "," + y, "");

        // Initialize a flag to detect if a bug occurs
        boolean bug = false;

        // Iterate through each movement in the input string
        for (char move : recordOfMovements.toCharArray()) {
            // Store the current position before the move
            String temp = x + "," + y;

            // Update the coordinates based on the movement direction
            x += dMovement.get(move)[0];
            y += dMovement.get(move)[1];

            // Check if the new position has already been visited
            if (!visited.containsKey(x + "," + y)) {
                // If not visited, check for potential bugs by looking at all movement directions
                for (char step : dMovement.keySet()) {
                    // Check if moving in any direction from the new position leads to a visited position
                    String newPosition = (x + dMovement.get(step)[0]) + "," + (y + dMovement.get(step)[1]);
                    if (!newPosition.equals(temp) && visited.containsKey(newPosition)) {
                        // If a bug is detected, set the flag and break the loop
                        bug = true;
                        break;
                    }
                }
            } else {
                // If the new position was already visited, set the bug flag
                bug = true;
            }

            // If a bug has been detected, exit the loop
            if (bug) {
                break;
            }

            // Mark the new position as visited
            visited.put(x + "," + y, "");
        }

        // After processing all movements, check if a bug was detected
        if (bug) {
            // Print 'BUG' if a bug was found
            System.out.println("BUG");
        } else {
            // Print 'OK' if no bugs were found
            System.out.println("OK");
        }

        scanner.close();
    }
}
// <END-OF-CODE>
