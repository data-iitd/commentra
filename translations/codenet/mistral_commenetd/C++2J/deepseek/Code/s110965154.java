import java.util.ArrayList;
import java.util.Scanner;

public class InsertionSort {

    // Function to sort the vector in ascending order using insertion sort algorithm
    public static void sort(ArrayList<Integer> a_rvecIntValue) {

        // Iterate through each element in the vector starting from the second element
        for (int i = 0; i < a_rvecIntValue.size(); i++) {
            if (i != 0) { // Check if we are not at the first element

                int iIntValue = a_rvecIntValue.get(i); // Get the value of the current element
                int j = i - 1; // Initialize a variable to store the index of the previous element
                while ((j >= 0) && (a_rvecIntValue.get(j) > iIntValue)) { // While the previous element is greater than the current element
                    a_rvecIntValue.set(j + 1, a_rvecIntValue.get(j)); // Swap the previous and next elements
                    j--; // Decrement the index of the previous element
                }
                a_rvecIntValue.set(j + 1, iIntValue); // Place the current element at its correct position
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

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        int iNum = scanner.nextInt(); // Read the number of elements from the standard input

        ArrayList<Integer> vecIntValue = new ArrayList<>(); // Create an empty vector to store the integers
        for (int i = 0; i < iNum; i++) {
            vecIntValue.add(scanner.nextInt()); // Add the integer to the vector
        }

        // Call the sorting function to sort the vector
        sort(vecIntValue);
    }
}
