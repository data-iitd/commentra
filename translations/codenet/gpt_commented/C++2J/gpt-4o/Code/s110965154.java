import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class InsertionSort {
    // Function prototype for the sorting function
    public static void sort(List<Integer> a_rvecIntValue) {
        // Iterate through each element in the list
        for (int i = 0; i < a_rvecIntValue.size(); i++) {
            // Check if we are not at the first element
            if (i != 0) {
                // Store the current element to be inserted
                int iIntValue = a_rvecIntValue.get(i);
                int j = i - 1; // Start comparing with the previous element

                // Move elements of a_rvecIntValue[0..i-1], that are greater than iIntValue,
                // to one position ahead of their current position
                while (j >= 0 && a_rvecIntValue.get(j) > iIntValue) {
                    a_rvecIntValue.set(j + 1, a_rvecIntValue.get(j)); // Shift element to the right
                    j--; // Move to the previous element
                }
                // Place the current element at its correct position
                a_rvecIntValue.set(j + 1, iIntValue);
            }

            // Print the current state of the sorted portion of the list
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

    public static void main(String[] args) {
        // Variable to hold the number of integers to be sorted
        Scanner scanner = new Scanner(System.in);
        int iNum = scanner.nextInt();

        // List to store the integers
        List<Integer> vecIntValue = new ArrayList<>();

        // Loop to read integers from input and store them in the list
        while (iNum > 0) {
            int iIntValue = scanner.nextInt(); // Read an integer
            vecIntValue.add(iIntValue); // Add the integer to the list
            iNum--; // Decrement the count of integers to read
        }

        // Call the sort function to sort the list of integers
        sort(vecIntValue);
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
