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

        // Step 3: Main function
        // The main function reads the number of integers to be sorted.
        // It then reads each integer and stores them in a vector.
        // It calls the `sort` function with the vector.

        Scanner sc = new Scanner(System.in);
        int iNum = sc.nextInt();
        Vector<Integer> vecIntValue = new Vector<Integer>();
        while (iNum > 0) {
            int iIntValue = sc.nextInt();
            vecIntValue.add(iIntValue);
            iNum--;
        }

        sort(vecIntValue);

        sc.close();
    }

    public static void sort(Vector<Integer> a_rvecIntValue) {

        // Step 4: Sort function implementation
        // The sort function uses the insertion sort algorithm.
        // It iterates through the vector, inserting each element in the correct position.
        // It prints the vector after each insertion to show the progress of the sorting process.

        for (int i = 0; i < a_rvecIntValue.size(); i++) {

            // If it's not the first element, insert it in the correct position
            if (i!= 0) {
                int iIntValue = a_rvecIntValue.get(i);
                int j = i - 1;
                while ((j >= 0) && (a_rvecIntValue.get(j) > iIntValue)) {
                    a_rvecIntValue.set(j+1, a_rvecIntValue.get(j));
                    j--;
                }
                a_rvecIntValue.set(j+1, iIntValue);
            }

            // Print the vector after each insertion
            for (int k = 0; k < a_rvecIntValue.size(); k++) {
                System.out.print(a_rvecIntValue.get(k));
                if (k!= a_rvecIntValue.size() - 1) {
                    System.out.print(" ");
                }
            }
            System.out.println();
        }
    }
}

// Step 5: Output
// The program outputs the sorted vector after each insertion.

