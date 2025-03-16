public class Main {
    public static void main(String[] args) {

        // Initialize a 3D array to hold information for 4 buildings, each with 3 floors and 10 rooms
        int[][][] info = new int[4][3][10];

        // Set all values in the 3D array to 0
        for (int i = 0; i < 4; i ++) {
            for (int j = 0; j < 3; j ++) {
                for (int k = 0; k < 10; k ++) { 
                    info[i][j][k] = 0; // Initialize each room to 0
                }
            }
        }

        // Create a Scanner object to read input from the user
        java.util.Scanner sc = new java.util.Scanner(System.in);
        
        // Read the number of entries to be processed
        int n = sc.nextInt();
        
        // Process each entry to update the information in the 3D array
        for (int i = 0; i < n; i ++) {
            // Read the building number, floor number, room number, and the number to add
            int built = sc.nextInt();
            int floor = sc.nextInt();
            int room = sc.nextInt();
            int num = sc.nextInt();
            
            // Update the corresponding room in the 3D array with the new number
            info[built - 1][floor - 1][room - 1] += num;
        }

        // Output the contents of the 3D array
        for (int i = 0; i < 4; i ++) {
            for (int j = 0; j < 3; j ++) {
                for (int k = 0; k < 10; k ++) {
                    // Print the value of each room in the current floor
                    System.out.print(" " + info[i][j][k]);
                }
                // Move to the next line after printing all rooms in a floor
                System.out.print("\n");
            }
            // Print a separator between buildings, except after the last building
            if (i != 4 - 1) { 
                System.out.print("####################\n"); 
            }
        }
    }
}
