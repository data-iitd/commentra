public class InsertionSort {
    public static void main(String[] args) {
        // Variable to hold the number of integers to be sorted
        int iNum = 0;
        // Read the number of integers from standard input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        iNum = scanner.nextInt();
        
        // Array to store the integers
        int[] arrIntValue = new int[iNum];
        
        // Loop to read integers from input and store them in the array
        for (int i = 0; i < iNum; i++) {
            arrIntValue[i] = scanner.nextInt(); // Read an integer
        }

        // Call the sort function to sort the array of integers
        sort(arrIntValue);
    }

    // Function to perform insertion sort on the array of integers
    public static void sort(int[] a_rarrIntValue) {
        // Iterate through each element in the array
        for (int i = 0; i < a_rarrIntValue.length; i++) {
            // Check if we are not at the first element
            if (i != 0) {
                // Store the current element to be inserted
                int iIntValue = a_rarrIntValue[i];
                int j = i - 1; // Start comparing with the previous element
                
                // Move elements of a_rarrIntValue[0..i-1], that are greater than iIntValue,
                // to one position ahead of their current position
                while ((j >= 0) && (a_rarrIntValue[j] > iIntValue)) {
                    a_rarrIntValue[j + 1] = a_rarrIntValue[j]; // Shift element to the right
                    j--; // Move to the previous element
                }
                // Place the current element at its correct position
                a_rarrIntValue[j + 1] = iIntValue;
            }

            // Print the current state of the sorted portion of the array
            for (int k = 0; k < a_rarrIntValue.length; k++) {
                System.out.print(a_rarrIntValue[k]); // Output the element
                // Print a space between elements, but not after the last element
                if (k != a_rarrIntValue.length - 1) {
                    System.out.print(" ");
                }
            }
            System.out.println(); // New line after printing the current state
        }
    }
}
