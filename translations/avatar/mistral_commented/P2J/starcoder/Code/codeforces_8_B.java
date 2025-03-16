// Initialize an empty dictionary to store the visited positions
String record_of_movements = input();
int x = 0, y = 0; // Initialize the starting position of the bug
Map<String, Integer> d_movement = new HashMap<String, Integer>(); // Define a dictionary to store the direction of movement
d_movement.put("L", 0);
d_movement.put("R", 0);
d_movement.put("U", 0);
d_movement.put("D", 0);
Map<Integer, Integer> d = new HashMap<Integer, Integer>(); // Initialize an empty dictionary to store the visited positions

// Iterate through each movement in the record
for (int i = 0; i < record_of_movements.length(); i++) {
    // Save the current position of the bug
    int temp_x = x;
    int temp_y = y;

    // Move the bug based on the given direction
    if (d_movement.get(record_of_movements.charAt(i)) == 0) {
        x += 1;
        d_movement.put(record_of_movements.charAt(i), 1);
    } else if (d_movement.get(record_of_movements.charAt(i)) == 1) {
        y += 1;
        d_movement.put(record_of_movements.charAt(i), 2);
    } else if (d_movement.get(record_of_movements.charAt(i)) == 2) {
        x -= 1;
        d_movement.put(record_of_movements.charAt(i), 3);
    } else if (d_movement.get(record_of_movements.charAt(i)) == 3) {
        y -= 1;
        d_movement.put(record_of_movements.charAt(i), 0);
    }

    // Check if the new position is already visited
    if (!d.containsKey(x) &&!d.containsKey(y)) {
        // If yes, check if there is a loop in the path
        for (int j = 0; j < d_movement.size(); j++) {
            if (d_movement.get(record_of_movements.charAt(i))!= j) {
                if (d.containsKey(x + d_movement.get(record_of_movements.charAt(i)), y + d_movement.get(record_of_movements.charAt(i)))) {
                    // If a loop is found, set the bug is trapped flag
                    bug = true;
                    break;
                }
            }
        }
    }

    // If the new position is not visited, set it as visited
    d.put(x, y);
}

// Check if the bug is trapped
if (bug) {
    System.out.println("BUG");
} else {
    System.out.println("OK");
}

