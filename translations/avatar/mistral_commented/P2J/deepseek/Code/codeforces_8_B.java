public class BugTrap {
    public static void main(String[] args) {
        // Initialize an empty dictionary to store the visited positions
        String recordOfMovements = System.console().readLine();
        int x = 0, y = 0; // Initialize the starting position of the bug
        int[][] dMovement = { // Define a dictionary to store the direction of movement
            {0, -1}, // L
            {0, 1},  // R
            {1, 0},  // U
            {-1, 0}  // D
        };
        java.util.Map<String, String> d = new java.util.HashMap<>(); // Initialize an empty dictionary to store the visited positions
        boolean bug = false; // Initialize a boolean variable to check if the bug is trapped

        // Iterate through each movement in the record
        for (char move : recordOfMovements.toCharArray()) {
            // Save the current position of the bug
            String temp = x + "," + y;

            // Move the bug based on the given direction
            if (move == 'L') {
                x += dMovement[0][0];
                y += dMovement[0][1];
            } else if (move == 'R') {
                x += dMovement[1][0];
                y += dMovement[1][1];
            } else if (move == 'U') {
                x += dMovement[2][0];
                y += dMovement[2][1];
            } else if (move == 'D') {
                x += dMovement[3][0];
                y += dMovement[3][1];
            }

            // Check if the new position is already visited
            String newPosition = x + "," + y;
            if (!d.containsKey(newPosition)) {
                // If yes, check if there is a loop in the path
                for (int[] step : dMovement) {
                    int newX = x + step[0];
                    int newY = y + step[1];
                    String checkPosition = newX + "," + newY;
                    if ((newX != x || newY != y) && d.containsKey(checkPosition)) {
                        // If a loop is found, set the bug is trapped flag
                        bug = true;
                        break;
                    }
                }
            }

            // If the new position is not visited, set it as visited
            d.put(newPosition, "");
        }

        // Check if the bug is trapped
        if (bug) {
            System.out.println("BUG");
        } else {
            System.out.println("OK");
        }
    }
}
