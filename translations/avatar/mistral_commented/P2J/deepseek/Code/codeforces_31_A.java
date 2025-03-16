import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Take an integer input from the user
        int y = scanner.nextInt();

        // Take a list of integers as input from the user
        int[] arr = new int[y];
        for (int i = 0; i < y; i++) {
            arr[i] = scanner.nextInt();
        }

        // Iterate through each index 'i' in the list 'arr'
        for (int i = 0; i < arr.length; i++) {
            // Iterate through each index 'j' in the list 'arr' (excluding the current index 'i')
            for (int j = 0; j < arr.length; j++) {
                // Check if the current indices 'i' and 'j' are equal, if yes then skip the current iteration
                if (i == j) {
                    continue;
                }
                // Iterate through each index 'k' in the list 'arr' (excluding the indices 'i' and 'j')
                for (int k = 0; k < arr.length; k++) {
                    // Check if the current indices 'i', 'j' and 'k' satisfy the given condition
                    if (k != i && k != j && arr[k] != arr[j] && arr[k] != arr[i] && arr[k] == arr[i] + arr[j]) {
                        // If the condition is true, print the indices 'i', 'j' and 'k' and exit the function
                        System.out.println((k + 1) + " " + (j + 1) + " " + (i + 1));
                        return;
                    }
                }
            }
        }
        // If no such indices are found, print -1
        System.out.println(-1);
    }
}
