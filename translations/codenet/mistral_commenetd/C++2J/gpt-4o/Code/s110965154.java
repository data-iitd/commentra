import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class InsertionSort {

    // Function to sort the list in ascending order using insertion sort algorithm
    public static void sort(List<Integer> a_rvecIntValue) {
        // Iterate through each element in the list starting from the second element
        for (int i = 0; i < a_rvecIntValue.size(); i++) {
            if (i != 0) { // Check if we are not at the first element
                int iIntValue = a_rvecIntValue.get(i); // Get the value of the current element
                int j = i - 1; // Initialize a variable to store the index of the previous element
                while (j >= 0 && a_rvecIntValue.get(j) > iIntValue) { // While the previous element is greater than the current element
                    a_rvecIntValue.set(j + 1, a_rvecIntValue.get(j)); // Swap the previous and next elements
                    j--; // Decrement the index of the previous element
                }
                a_rvecIntValue.set(j + 1, iIntValue); // Place the current element at its correct position
            }

            // Print the sorted list after each insertion
            for (int k = 0; k < a_rvecIntValue.size(); k++) {
                System.out.print(a_rvecIntValue.get(k)); // Print the value of the current element
                if (k != a_rvecIntValue.size() - 1) { // Check if we are not at the last element
                    System.out.print(" "); // Print a space if not
                }
            }
            System.out.println(); // Print a newline after each pass
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int iNum = scanner.nextInt(); // Read the number of elements from the standard input
        List<Integer> vecIntValue = new ArrayList<>(); // Create an empty list to store the integers
        
        while (iNum > 0) {
            int iIntValue = scanner.nextInt(); // Read the next integer from the standard input
            vecIntValue.add(iIntValue); // Add the integer to the list
            iNum--; // Decrement the counter
        }

        // Call the sorting function to sort the list
        sort(vecIntValue);
        
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
