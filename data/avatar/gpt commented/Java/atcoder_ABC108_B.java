import java.util.Scanner;

public class Main {
    
    // Method to calculate the new position based on two input positions
    public static int[] revpos(int[] p, int[] q) {
        // Initialize a vector to hold the difference between the two positions
        int[] vec = {0, 0};
        
        // Calculate the difference between position p and q
        for (int i = 0; i < vec.length; i++) {
            vec[i] = p[i] - q[i];
        }
        
        // Rotate the vector to get the new direction
        int tmp = 0;
        tmp = vec[0];
        vec[0] = vec[1];
        vec[1] = -tmp;
        
        // Initialize a new position array
        int[] newpos = {0, 0};
        
        // Calculate the new position by adding the rotated vector to position q
        for (int i = 0; i < newpos.length; i++) {
            newpos[i] = q[i] + vec[i];
        }
        
        // Return the newly calculated position
        return newpos;
    }

    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scan = new Scanner(System.in);
        
        // Array to hold the input values
        int[] input = {0, 0, 0, 0};
        
        // Read four integers from the user input
        for (int i = 0; i < input.length; i++) {
            input[i] = scan.nextInt();
        }
        
        // Close the scanner to prevent resource leaks
        scan.close();
        
        // Initialize a 2D array to hold positions
        int[][] position = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};
        
        // Assign input values to the first two positions
        position[0][0] = input[0];
        position[0][1] = input[1];
        position[1][0] = input[2];
        position[1][1] = input[3];
        
        // Calculate the new position based on the first two positions
        position[2] = revpos(position[0], position[1]);
        
        // Calculate another new position based on the second and third positions
        position[3] = revpos(position[1], position[2]);
        
        // Check if the first position is equal to the result of revpos on the last two positions
        if (position[0] == revpos(position[2], position[3])) {
            System.out.println("OK");
        }
        
        // Prepare an output array to hold the results
        int[] output = {0, 0, 0, 0};
        
        // Assign the calculated positions to the output array
        output[0] = position[2][0];
        output[1] = position[2][1];
        output[2] = position[3][0];
        output[3] = position[3][1];
        
        // Print the output values
        for (int i : output) {
            System.out.println(i);
        }
    }
}
