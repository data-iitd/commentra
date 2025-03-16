import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int y = scanner.nextInt();  // Take an integer input for variable y
        int[] arr = new int[y];  // Create an array of size y
        for (int i = 0; i < y; i++) {
            arr[i] = scanner.nextInt();  // Take a list of integers as input and store it in arr
        }

        // Iterate through the list arr using three nested loops
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr.length; j++) {
                if (i == j) {
                    continue;  // Skip if i and j are the same index
                }
                for (int k = 0; k < arr.length; k++) {
                    if (arr[k] != arr[j] && arr[k] != arr[i] && arr[k] == arr[i] + arr[j]) {
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
