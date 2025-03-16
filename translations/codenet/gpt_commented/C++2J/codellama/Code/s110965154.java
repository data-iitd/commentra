/*
 * InsertionSort.java
 *
 *  Created on: 2014/07/25
 *      Author: WanWan1985
 */
import java.util.Scanner;
import java.util.Vector;

public class InsertionSort {
    public static void main(String[] args) {
        // Variable to hold the number of integers to be sorted
        int iNum = 0;
        // Read the number of integers from standard input
        Scanner sc = new Scanner(System.in);
        iNum = sc.nextInt();
        
        // Vector to store the integers
        Vector<Integer> vecIntValue = new Vector<Integer>();
        
        // Loop to read integers from input and store them in the vector
        while (iNum > 0) {
            int iIntValue = 0;
            iIntValue = sc.nextInt(); // Read an integer
            vecIntValue.add(iIntValue); // Add the integer to the vector
            iNum--; // Decrement the count of integers to read
        }

        // Call the sort function to sort the vector of integers
        sort(vecIntValue);

        return; // Exit the program
    }

    // Function to perform insertion sort on the vector of integers
    public static void sort(Vector<Integer> a_rvecIntValue) {
        // Iterate through each element in the vector
        for (int i = 0; i < a_rvecIntValue.size(); i++) {
            // Check if we are not at the first element
            if (i != 0) {
                // Store the current element to be inserted
                int iIntValue = a_rvecIntValue.get(i);
                int j = i - 1; // Start comparing with the previous element
                
                // Move elements of a_rvecIntValue[0..i-1], that are greater than iIntValue,
                // to one position ahead of their current position
                while ((j >= 0) && (a_rvecIntValue.get(j) > iIntValue)) {
                    a_rvecIntValue.set(j + 1, a_rvecIntValue.get(j)); // Shift element to the right
                    j--; // Move to the previous element
                }
                // Place the current element at its correct position
                a_rvecIntValue.set(j + 1, iIntValue);
            }

            // Print the current state of the sorted portion of the vector
            for (int k = 0; k < a_rvecIntValue.size(); k++) {
                System.out.print(a_rvecIntValue.get(k)); // Output the element
                // Print a space between elements, but not after the last element
                if (k != a_rvecIntValue.size() - 1) {
                    System.out.print(" ");
                }
            }
            System.out.println(); // New line after printing the current state
        }
    }
}

