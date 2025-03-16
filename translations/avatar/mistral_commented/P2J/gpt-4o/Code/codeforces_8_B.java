import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class BugMovement {
    public static void main(String[] args) {
        // Initialize an empty dictionary to store the visited positions
        Scanner scanner = new Scanner(System.in);
        String recordOfMovements = scanner.nextLine();
        int x = 0, y = 0; // Initialize the starting position of the bug

        // Define a map to store the direction of movement
        Map<Character, int[]> dMovement = new HashMap<>();
        dMovement.put('L', new int[]{0, -1});
        dMovement.put('R', new int[]{0, 1});
        dMovement.put('U', new int[]{1, 0});
        dMovement.put('D', new int[]{-1, 0});

        // Initialize an empty map to store the visited positions
        Map<String, String> d = new HashMap<>();
        d.put(x + "," + y, ""); // Store the starting position

        boolean bug = false; // Initialize a boolean variable to check if the bug is trapped

        // Iterate through each movement in the record
        for (char move : recordOfMovements.toCharArray()) {
            // Save the current position of the bug
            int tempX = x;
            int tempY = y;

            // Move the bug based on the given direction
            x += dMovement.get(move)[0];
            y += dMovement.get(move)[1];

            // Check if the new position is already visited
            if (!d.containsKey(x + "," + y)) {
                // If yes, check if there is a loop in the path
                for (char step : dMovement.keySet()) {
                    int newX = x + dMovement.get(step)[0];
                    int newY = y + dMovement.get(step)[1];
                    if (newX != tempX || newY != tempY) {
                        if (d.containsKey(newX + "," + newY)) {
                            // If a loop is found, set the bug is trapped flag
                            bug = true;
                            break;
                        }
                    }
                }
            }

            // If the new position is not visited, set it as visited
            d.put(x + "," + y, "");
        }

        // Check if the bug is trapped
        if (bug) {
            System.out.println("BUG");
        } else {
            System.out.println("OK");
        }

        scanner.close();
    }
}
// <END-OF-CODE>
