

String recordOfMovements = scanner.nextLine();  // Take input for the movements of a character
int x = 0, y = 0;  // Initialize the starting position (x, y) to (0, 0)
Map<String, Integer> dMovement = new HashMap<>();  // Initialize a map that maps each direction to its coordinate changes
dMovement.put("L", 0);
dMovement.put("R", 1);
dMovement.put("U", 2);
dMovement.put("D", 3);
Map<String, String> d = new HashMap<>();  // Initialize a map to keep track of visited positions
d.put(x + "," + y, "");  // Add the starting position to the map d
boolean bug = false;  // Set a flag bug to False

for (int i = 0; i < recordOfMovements.length(); i++) {  // Iterate over each movement in the input
    int tempX = x, tempY = y;  // Store the current position in temporary variables
    char move = recordOfMovements.charAt(i);  // Get the current movement
    x += dMovement.get(String.valueOf(move));  // Update the x-coordinate based on the direction
    y += dMovement.get(String.valueOf(move));  // Update the y-coordinate based on the direction
    
    if (!d.containsKey(x + "," + y)) {  // Check if the new position has been visited before
        for (Map.Entry<String, Integer> entry : dMovement.entrySet()) {  // Check the surrounding positions
            if ((x + dMovement.get(entry.getKey()))!= tempX && (y + dMovement.get(entry.getKey()))!= tempY && d.containsKey((x + dMovement.get(entry.getKey())) + "," + (y + dMovement.get(entry.getKey())))) {
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
    
    d.put(x + "," + y, "");  // Add the new position to the map d
}

if (bug) {  // Check if a bug was detected
    System.out.println("BUG");  // Print 'BUG' if a bug was detected
} else {
    System.out.println("OK");  // Print 'OK' if no bug was detected
}

