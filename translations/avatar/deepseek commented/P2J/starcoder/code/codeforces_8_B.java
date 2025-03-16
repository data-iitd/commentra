
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String record_of_movements = sc.next();  // Take input for the movements of a character
        int x = 0, y = 0;  // Initialize the starting position (x, y) to (0, 0)
        Map<String, Integer[]> d_movement = new HashMap<String, Integer[]>();  // Define a dictionary that maps each direction to its coordinate changes
        d_movement.put("L", new Integer[] {0, -1});
        d_movement.put("R", new Integer[] {0, 1});
        d_movement.put("U", new Integer[] {1, 0});
        d_movement.put("D", new Integer[] {-1, 0});
        Map<String, String> d = new HashMap<String, String>();  // Initialize a dictionary to keep track of visited positions
        boolean bug = false;  // Set a flag bug to False

        for (int i = 0; i < record_of_movements.length(); i++) {  // Iterate over each movement in the input
            int temp_x = x;  // Store the current position in a temporary variable
            int temp_y = y;
            x += d_movement.get(record_of_movements.substring(i, i + 1))[0];  // Update the x-coordinate based on the direction
            y += d_movement.get(record_of_movements.substring(i, i + 1))[1];  // Update the y-coordinate based on the direction

            if (x + " " + y not in d) {  // Check if the new position has been visited before
                for (String step : d_movement.keySet()) {  // Check the surrounding positions
                    if (x + d_movement.get(step)[0] + " " + y + d_movement.get(step)[1]!= temp_x + " " + temp_y && (x + d_movement.get(step)[0] + " " + y + d_movement.get(step)[1]) in d) {
                        bug = true;  // Set the bug flag to True if a bug is detected
                        break;  // Break out of the loop if a bug is detected
                    }
                }
            } else {
                bug = true;  // Set the bug flag to True if the new position has been visited before
            }

            if (bug) {  // Check if a bug was detected
                break;  // Break out of the loop if a bug was detected
            }

            d.put(x + " " + y, "");  // Add the new position to the dictionary d
        }

        if (bug) {  // Check if a bug was detected
            System.out.println("BUG");  // Print 'BUG' if a bug was detected
        } else {
            System.out.println("OK");  // Print 'OK' if no bug was detected
        }
    }
}

