import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize an empty ArrayList to store the results
        ArrayList<Integer> result = new ArrayList<Integer>();
        
        Scanner insert = new Scanner(System.in); // Create a Scanner object to read user input
        int n = -1; // Initialize n with an invalid value to ensure the while loop runs at least once

        // Infinite loop to read user input until n equals 0
        while(true) {
            String line = insert.nextLine(); // Read a line of user input
            n = Integer.parseInt(line); // Parse the line as an integer and assign it to n

            // Exit the loop if n equals 0
            if(n==0 ){
                break;
            }

            // Initialize an empty arraylist to store the input array
            ArrayList<Integer> inputList = new ArrayList<Integer>();

            // Read the size of the array and initialize the input array
            for(int i = 0; i < n;i++) {
                line = insert.nextLine(); // Read the next line containing the input array elements
                String[] array2 = line.split(" "); // Split the line into an array of strings using space as delimiter
                int[] input = new int[n]; // Initialize the input array with the size equal to n

                // Initialize the input array with user input and calculate the sum
                for(int j =0; j < n; j++) {
                    input[j] = Integer.parseInt(array2[j]); // Parse each string in the array2 and assign it to the corresponding index in the input array
                    sum += input[j]; // Add the current element to the sum
                }

                // Calculate the average of the input array
                double avg = (double)sum/(double)n;

                // Initialize a counter to store the number of elements less than or equal to the average
                int num = 0;

                // Count the number of elements less than or equal to the average
                for(int j =0; j < n; j++) {
                    if(input[j] <= avg) {
                        num++; // Increment the counter if the current element is less than or equal to the average
                    }
                }

                // Add the counter to the result ArrayList
                result.add(num);

                // Clear the input array and sum variable for the next iteration
                input = new int[n];
                sum = 0;
            }

            // Print the results for each input
            for(int i = 0;i < result.size();i++) {
                if(result.get(i) == -1) { // Check if the current result is -1 (indicating an empty input array)
                    System.out.println("NONE"); // Print "NONE" if the result is -1
                }
                else {
                    System.out.println(result.get(i)); // Print the result otherwise
                }
            }
        }
    }
}
