import java.util.Scanner; // Importing Scanner class for input

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in); // Creating a Scanner object to read input
        int i, j, x = 0, y = 0, k = 0, dx, dy; // Initializing variables for coordinates and loop counters
        boolean flag = true; // Flag to check for "BUG" pattern
        String s; // Variable to store the input string
        char[] ch = new char[100]; // Array to store the input string as characters
        int[][] co = new int[2][101]; // 2D array to store the coordinates

        s = scan.next(); // Reading the input string
        ch = s.toCharArray(); // Converting the input string to a character array
        co[0][k] = x; // Storing the initial x-coordinate
        co[1][k] = y; // Storing the initial y-coordinate
        ++k; // Incrementing the counter for storing coordinates

        // Updating the positions based on the direction commands
        for (i = 0; i < s.length(); ++i) {
            switch (ch[i]) {
                case 'L': --x; break; // Moving left
                case 'R': ++x; break; // Moving right
                case 'U': ++y; break; // Moving up
                case 'D': --y; break; // Moving down
            }
            co[0][k] = x; // Storing the updated x-coordinate
            co[1][k] = y; // Storing the updated y-coordinate
            ++k; // Incrementing the counter for storing coordinates
        }

        // Checking for "BUG" pattern
        for (i = 0; i < k - 3; ++i) {
            for (j = i + 3; j < k; ++j) {
                dx = co[0][i] - co[0][j]; // Calculating the difference in x-coordinates
                dy = co[1][i] - co[1][j]; // Calculating the difference in y-coordinates
                if (dx < 0) dx *= -1; // Taking the absolute value of dx
                if (dy < 0) dy *= -1; // Taking the absolute value of dy
                if ((dx <= 1 && dy == 0) || (dy <= 1 && dx == 0)) { // Checking if the movement forms a "bug" pattern
                    flag = false; // Setting the flag to false if a "bug" pattern is found
                    break; // Breaking out of the inner loop
                }
            }
            if (!flag) break; // Breaking out of the outer loop if a "bug" pattern is found
        }

        // Outputting the result
        if (flag) System.out.println("OK"); // Printing "OK" if no "bug" pattern is found
        else System.out.println("BUG"); // Printing "BUG" if a "bug" pattern is found
    }
}
