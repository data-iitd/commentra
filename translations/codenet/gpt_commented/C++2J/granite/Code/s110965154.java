
/*
 * InsertionSort.java
 *
 *  Created on: 2014/07/25
 *      Author: Wanwan1985
 */
import java.util.Scanner;
import java.util.Vector;

public class s110965154{
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Variable to hold the number of integers to be sorted
        int num = 0;
        // Read the number of integers from standard input
        num = scanner.nextInt();

        // Vector to store the integers
        Vector<Integer> intValueVector = new Vector<Integer>();

        // Loop to read integers from input and store them in the vector
        while (num > 0) {
            int intValue = 0;
            intValue = scanner.nextInt(); // Read an integer
            intValueVector.add(intValue); // Add the integer to the vector
            num--; // Decrement the count of integers to read
        }

        // Call the sort function to sort the vector of integers
        sort(intValueVector);

        // Close the Scanner object to release system resources
        scanner.close();
    }

    // Function to perform insertion sort on the vector of integers
    public static void sort(Vector<Integer> intValueVector) {
        // Iterate through each element in the vector
        for (int i = 0; i < intValueVector.size(); i++) {
            // Check if we are not at the first element
            if (i!= 0) {
                // Store the current element to be inserted
                int intValue = intValueVector.get(i);
                int j = i - 1; // Start comparing with the previous element

                // Move elements of intValueVector[0..i-1], that are greater than intValue,
                // to one position ahead of their current position
                while ((j >= 0) && (intValueVector.get(j) > intValue)) {
                    intValueVector.set(j + 1, intValueVector.get(j)); // Shift element to the right
                    j--; // Move to the previous element
                }
                // Place the current element at its correct position
                intValueVector.set(j + 1, intValue);
            }

            // Print the current state of the sorted portion of the vector
            for (int k = 0; k < intValueVector.size(); k++) {
                System.out.print(intValueVector.get(k)); // Output the element
                // Print a space between elements, but not after the last element
                if (k!= intValueVector.size() - 1) {
                    System.out.print(" ");
                }
            }
            System.out.println(); // New line after printing the current state
        }
    }
}
