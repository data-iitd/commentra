

import java.util.Scanner;

public class codeforces_31_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int y = scanner.nextInt();  // Take an integer input for variable y
        int[] arr = new int[y];  // Create an array of size y to store the input
        for (int i = 0; i < y; i++) {
            arr[i] = scanner.nextInt();  // Take an integer input for each element of arr
        }

        // Iterate through the array arr using three nested loops
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < y; j++) {
                if (i == j) {
                    continue;  // Skip if i and j are the same index
                }
                for (int k = 0; k < y; k++) {
                    if (arr[k]!= arr[j] && arr[k]!= arr[i] && arr[k] == arr[i] + arr[j]) {
                        // Check if arr[k] is the sum of arr[i] and arr[j] and different from both
                        System.out.println((k + 1) + " " + (j + 1) + " " + (i + 1));  // Print the positions of arr[k], arr[j], and arr[i] (1-indexed)
                        return;  // Exit the program
                    }
                }
            }
        }
        System.out.println(-1);  // Print -1 if no such element is found
    }
}

