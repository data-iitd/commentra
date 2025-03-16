
import java.util.Scanner ;

// Create a new Scanner object to read input from the standard input stream
public class Main {

    // Define a static method to reverse the order of elements in an array
    public static int[] revpos(int[] p, int[] q) {
        int[] vec = { 0, 0 }; // Initialize a temporary vector with zeros

        // Iterate through the elements of the vector and calculate their differences
        for (int i = 0; i < vec.length; i++) {
            vec[i] = p[i] - q[i]; // Subtract corresponding elements of p and q and store the result in vec[i]
        }

        // Swap the first and second elements of the vector
        int tmp = 0;
        tmp = vec[0];
        vec[0] = vec[1];
        vec[1] = -tmp;

        // Calculate the new positions by adding the vector elements to the corresponding elements of q
        int[] newpos = { 0, 0 };
        for (int i = 0; i < newpos.length; i++) {
            newpos[i] = q[i] + vec[i];
        }

        // Return the new positions
        return newpos;
    }

    // Define the main method to read input and perform the required calculations
    public static void main(String[] args) {

        // Create a new Scanner object to read input from the standard input stream
        Scanner scan = new Scanner(System.in);

        // Read four integers as input and store them in an array
        int[] input = { 0, 0, 0, 0 };
        for (int i = 0; i < input.length; i++) {
            input[i] = scan.nextInt(); // Read an integer from the standard input stream and store it in input[i]
        }

        // Close the Scanner object to prevent resource leaks
        scan.close();

        // Define a 2D array to store the positions of the four integers
        int[][] position = { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } };
        position[0][0] = input[0]; // Store the first integer as the x-coordinate of the first position
        position[0][1] = input[1]; // Store the second integer as the y-coordinate of the first position
        position[1][0] = input[2]; // Store the third integer as the x-coordinate of the second position
        position[1][1] = input[3]; // Store the fourth integer as the y-coordinate of the second position

        // Calculate the reversed positions of the first and second positions
        int[][] reversedPositions = new int[2][2];
        reversedPositions[0] = revpos(position[0], position[1]);
        reversedPositions[1] = revpos(position[1], position[0]);

        // Check if the first and second reversed positions are equal
        if (position[0] == reversedPositions[1]) { // Compare the first position with the reversed second position
            System.out.println("OK"); // Print "OK" if they are equal
        }

        // Calculate the output array by taking the reversed positions and swapping their x and y coordinates
        int[] output = { 0, 0, 0, 0 };
        output[0] = reversedPositions[2][0]; // Store the x-coordinate of the reversed third position in output[0]
        output[1] = reversedPositions[2][1]; // Store the y-coordinate of the reversed third position in output[1]
        output[2] = reversedPositions[3][0]; // Store the x-coordinate of the reversed fourth position in output[2]
        output[3] = reversedPositions[3][1]; // Store the y-coordinate of the reversed fourth position in output[3]

        // Print the output array
        for (int i : output) {
            System.out.println(i);
        }
    }
}

