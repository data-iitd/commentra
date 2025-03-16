public class Main {
    public static void main(String[] args) {

        // Declare a 3-dimensional integer array `info` with dimensions 4 x 3 x 10.
        int[][][] info = new int[4][3][10];

        // Initialize the array with zeros using nested for loops.
        for (int i = 0; i < 4; i ++) {
            for (int j = 0; j < 3; j ++) {
                for (int k = 0; k < 10; k ++) {
                    info[i][j][k] = 0;
                }
            }
        }

        // Create a `Scanner` object to read input from the standard input.
        java.util.Scanner sc = new java.util.Scanner(System.in);

        // Read an integer `n` from the standard input, which represents the number of buildings and their floors and rooms.
        int n = sc.nextInt();

        // Use nested for loops to read the number of people in each room of each floor of each building and add it to the corresponding element in the `info` array.
        for (int i = 0; i < n; i ++) {
            int built = sc.nextInt(); // Read the building number.
            int floor = sc.nextInt(); // Read the floor number.
            int room = sc.nextInt(); // Read the room number.
            int num = sc.nextInt(); // Read the number of people in the room.
            info[built - 1][floor - 1][room - 1] += num; // Add the number of people to the corresponding element in the `info` array.
        }

        // Print out the contents of the `info` array using nested for loops and newline characters.
        for (int i = 0; i < 4; i ++) {
            for (int j = 0; j < 3; j ++) {
                for (int k = 0; k < 10; k ++) {
                    System.out.print(" " + info[i][j][k]); // Print the number of people in the room.
                }
                System.out.print("\n"); // Print a newline character to move to the next line.
            }
            if (i != 4 - 1) { // If this is not the last building, print horizontal lines to separate the buildings.
                System.out.print("####################\n");
            }
        }
    }
}