import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read an integer input which represents the size of the array
        int y = scanner.nextInt();

        // Read a line of input, split it into individual strings, convert them to integers, and store them in a list
        int[] arr = new int[y];
        for (int i = 0; i < y; i++) {
            arr[i] = scanner.nextInt();
        }

        // Iterate over each element in the array using index i
        for (int i = 0; i < arr.length; i++) {
            // Iterate over each element in the array using index j
            for (int j = 0; j < arr.length; j++) {
                // Skip the iteration if both indices are the same
                if (i == j) {
                    continue;
                }
                // Iterate over each element in the array using index k
                for (int k = 0; k < arr.length; k++) {
                    // Check if the current element at index k is different from elements at indices i and j,
                    // and if it is equal to the sum of the elements at indices i and j
                    if (k != j && k != i && arr[k] == arr[i] + arr[j]) {
                        // Print the 1-based indices of the elements that satisfy the condition
                        System.out.println((k + 1) + " " + (j + 1) + " " + (i + 1));
                        // Exit the program after finding the first valid triplet
                        return;
                    }
                }
            }
        }

        // If no valid triplet is found, print -1
        System.out.println(-1);
    }
}
