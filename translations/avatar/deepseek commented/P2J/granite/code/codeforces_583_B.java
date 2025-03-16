

import java.util.Scanner;

public class codeforces_583_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read the number of elements from the user
        int n = scanner.nextInt();
        // Read the list of integers from the user input
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        // Initialize variables to track the current level and the number of turns
        int currentLevel = 0;
        int counter = 0;
        int counterTurns = -1;

        // Start a while loop that continues until all elements are processed
        while (counter < n) {
            // Increment the turn counter
            counterTurns++;
            // Iterate over the list 'a' to process each element
            for (int i = 0; i < n; i++) {
                // Check if the element is not -1 and is less than or equal to the current level
                if (a[i]!= -1 && a[i] <= currentLevel) {
                    // Increment the counter and mark the element as processed
                    counter++;
                    a[i] = -1;
                }
            }
            // Reverse the list 'a' to process elements in a different order in the next iteration
            reverse(a);
        }

        // Print the number of turns taken to process all elements
        System.out.println(counterTurns);
    }

    public static void reverse(int[] a) {
        int left = 0;
        int right = a.length - 1;
        while (left < right) {
            int temp = a[left];
            a[left] = a[right];
            a[right] = temp;
            left++;
            right--;
        }
    }
}
