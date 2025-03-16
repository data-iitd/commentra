import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class InsertionSort {

    // Step 1: Define the sort function
    // The `sort` function is defined to take a list of integers.

    public static void sort(List<Integer> a_rvecIntValue) {
        // Step 4: Sort function implementation
        // The sort function uses the insertion sort algorithm.
        // It iterates through the list, inserting each element in the correct position.
        // It prints the list after each insertion to show the progress of the sorting process.

        for (int i = 0; i < a_rvecIntValue.size(); i++) {
            // If it's not the first element, insert it in the correct position
            if (i != 0) {
                int iIntValue = a_rvecIntValue.get(i);
                int j = i - 1;
                while (j >= 0 && a_rvecIntValue.get(j) > iIntValue) {
                    a_rvecIntValue.set(j + 1, a_rvecIntValue.get(j));
                    j--;
                }
                a_rvecIntValue.set(j + 1, iIntValue);
            }

            // Print the list after each insertion
            for (int k = 0; k < a_rvecIntValue.size(); k++) {
                System.out.print(a_rvecIntValue.get(k));
                if (k != a_rvecIntValue.size() - 1) {
                    System.out.print(" ");
                }
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        // Step 3: Main function
        // The main function reads the number of integers to be sorted.
        // It then reads each integer and stores them in a list.
        // It calls the `sort` function with the list.

        Scanner scanner = new Scanner(System.in);
        int iNum = scanner.nextInt();
        List<Integer> vecIntValue = new ArrayList<>();

        while (iNum > 0) {
            int iIntValue = scanner.nextInt();
            vecIntValue.add(iIntValue);
            iNum--;
        }

        sort(vecIntValue);
        scanner.close();
    }
}

// Step 5: Output
// The program outputs the sorted list after each insertion.
