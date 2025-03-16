// Initialize an empty dictionary to store the visited positions
HashMap<String, String> record_of_movements = new HashMap<>();
int x = 0, y = 0; // Initialize the starting position of the bug
HashMap<String, int[]> d_movement = new HashMap<>();
// Define a dictionary to store the direction of movement
d_movement.put("L", new int[] {0, -1});
d_movement.put("R", new int[] {0, 1});
d_movement.put("U", new int[] {1, 0});
d_movement.put("D", new int[] {-1, 0});
HashMap<String, String> d = new HashMap<>();
// Initialize an empty dictionary to store the visited positions
d.put(x + " " + y, "");
boolean bug = false; // Initialize a boolean variable to check if the bug is trapped

// Iterate through each movement in the record
for (String move : record_of_movements.keySet()) {
    // Save the current position of the bug
    String temp = x + " " + y;

    // Move the bug based on the given direction
    x += d_movement.get(move)[0];
    y += d_movement.get(move)[1];

    // Check if the new position is already visited
    if (!d.containsKey(x + " " + y)) {
        // If yes, check if there is a loop in the path
        for (String step : d_movement.keySet()) {
            if (!(x + " " + y).equals(temp) && d.containsKey((x + d_movement.get(step)[0]) + " " + (y + d_movement.get(step)[1]))) {
                // If a loop is found, set the bug is trapped flag
                bug = true;
                break;
            }
        }
    }

    // If the new position is not visited, set it as visited
    d.put(x + " " + y, "");
}

// Check if the bug is trapped
if (bug) {
    System.out.println("BUG");
} else {
    System.out.println("OK");
}

