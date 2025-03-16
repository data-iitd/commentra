
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
 
        Scanner sc = new Scanner(System.in); // Create a scanner to read from the standard input
        int num = sc.nextInt(); // Read the number of elements from the standard input
 
        Vector<Integer> vecIntValue = new Vector<Integer>(); // Create an empty vector to store the integers
        while (num > 0) {
            int intValue = sc.nextInt(); // Read the next integer from the standard input
            vecIntValue.add(intValue); // Add the integer to the vector
            num--; // Decrement the counter
        }
 
        // Call the sorting function to sort the vector
        sort(vecIntValue);
    }
 
    // Function to sort the vector in ascending order using insertion sort algorithm
    public static void sort(Vector<Integer> a_rvecIntValue) {
 
        // Iterate through each element in the vector starting from the second element
        for (int i = 0; i < a_rvecIntValue.size(); i++) {
            if (i != 0) { // Check if we are not at the first element
 
                int intValue = a_rvecIntValue.get(i); // Get the value of the current element
                int j = i - 1; // Initialize a variable to store the index of the previous element
                while ((j >= 0) && (a_rvecIntValue.get(j) > intValue)) { // While the previous element is greater than the current element
                    a_rvecIntValue.set(j+1, a_rvecIntValue.get(j)); // Swap the previous and next elements
                    j--; // Decrement the index of the previous element
                }
                a_rvecIntValue.set(j+1, intValue); // Place the current element at its correct position
            }
 
            // Print the sorted vector after each insertion
            for (int k = 0; k < a_rvecIntValue.size(); k++) {
                System.out.print(a_rvecIntValue.get(k)); // Print the value of the current element
                if (k != a_rvecIntValue.size() - 1) { // Check if we are not at the last element
                    System.out.print(" "); // Print a space if not
                }
            }
            System.out.println(); // Print a newline after each pass
        }
    }
}

