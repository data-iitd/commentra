// Read the input string representing movements
String record_of_movements = scanner.nextLine();

// Initialize the starting coordinates (x, y) at (0, 0)
int x = 0, y = 0;

// Define the movement directions: Left (L), Right (R), Up (U), Down (D)
Map<Character, int[]> d_movement = new HashMap<Character, int[]>();
d_movement.put('L', new int[] {0, -1});
d_movement.put('R', new int[] {0, 1});
d_movement.put('U', new int[] {1, 0});
d_movement.put('D', new int[] {-1, 0});

// Create a dictionary to track visited coordinates, starting with the initial position
Map<Integer, Integer> d = new HashMap<Integer, Integer>();
d.put(x, y);

// Initialize a flag to detect if a bug occurs
boolean bug = false;

// Iterate through each movement in the input string
for (char move : record_of_movements.toCharArray()) {
    // Store the current position before the move
    int temp_x = x, temp_y = y;

    // Update the coordinates based on the movement direction
    x += d_movement.get(move)[0];
    y += d_movement.get(move)[1];

    // Check if the new position has already been visited
    if (!d.containsKey(x) ||!d.containsKey(y)) {
        // If not visited, check for potential bugs by looking at all movement directions
        for (char step : d_movement.keySet()) {
            // Check if moving in any direction from the new position leads to a visited position
            if ((x + d_movement.get(step)[0]!= temp_x || y + d_movement.get(step)[1]!= temp_y) &&
                d.containsKey(x + d_movement.get(step)[0]) && d.containsKey(y + d_movement.get(step)[1])) {
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
    d.put(x, y);
}

// After processing all movements, check if a bug was detected
if (bug) {
    // Print 'BUG' if a bug was found
    System.out.println("BUG");
} else {
    // Print 'OK' if no bugs were found
    System.out.println("OK");
}

