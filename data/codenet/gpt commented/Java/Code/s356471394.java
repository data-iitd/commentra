import java.util.Scanner;

public class Main {

    // Create a Scanner object for input
    static Scanner sc = new Scanner(System.in);
    
    // Read the first line of input and split it into an array of strings
    static String[] nums = sc.nextLine().split(" ");

    // Parse the dimensions of the room and the distance D
    static int N = Integer.parseInt(nums[0]); // Number of rows
    static int M = Integer.parseInt(nums[1]); // Number of columns
    static char[][] room = new char[N][M]; // 2D array to represent the room
    static int D = Integer.parseInt(nums[2]); // Distance for placing items
    static int num = 0; // Counter for the number of valid placements

    public static void main(String[] args) {
        // Input the room configuration from the user
        inputRoom();

        // Check if the room can accommodate items horizontally
        if (M >= D) {
            setWE(); // Set items in the West-East direction
        }

        // Check if the room can accommodate items vertically
        if (N >= D) {
            setNS(); // Set items in the North-South direction
        }

        // Output the total number of valid placements
        System.out.println(num);
        sc.close(); // Close the scanner to free resources
    }

    // Method to check and count valid placements in the West-East direction
    private static void setWE() {
        boolean canPut = true; // Flag to check if placement is possible

        // Iterate through each row
        for (int i = 0; i < N; i++) {
            // Iterate through each starting column for placement
            for (int j = 0; j < M - D + 1; j++) {
                canPut = true; // Reset the flag for each new position

                // Check if the next D cells in the row are free
                for(int k = 0; k < D; k++){
                    if (Main.room[i][j + k] == '#') { // If a wall is encountered
                        canPut = false; // Mark placement as not possible
                        break; // Exit the loop early
                    }
                }

                // If placement is possible, increment the counter
                if (canPut == true) {
                    num++;
                }
            }
        }
    }

    // Method to check and count valid placements in the North-South direction
    private static void setNS() {
        boolean canPut = true; // Flag to check if placement is possible

        // Iterate through each column
        for (int i = 0; i < M; i++) {
            // Iterate through each starting row for placement
            for (int j = 0; j < N - D + 1; j++) {
                canPut = true; // Reset the flag for each new position

                // Check if the next D cells in the column are free
                for(int k = 0; k < D; k++){
                    if (Main.room[j + k][i] == '#') { // If a wall is encountered
                        canPut = false; // Mark placement as not possible
                        break; // Exit the loop early
                    }
                }

                // If placement is possible, increment the counter
                if (canPut == true) {
                    num++;
                }
            }
        }
    }

    // Method to input the room configuration from the user
    private static void inputRoom() {
        String str_room = ""; // Temporary string to hold each row of the room

        // Read each row of the room configuration
        for (int i = 0; i < N; i++) {
            str_room = sc.nextLine(); // Read the row as a string
            Main.room[i] = str_room.toCharArray(); // Convert the string to a char array
        }
    }
}
