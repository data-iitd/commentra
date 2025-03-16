
import java.util.Scanner;

public class CutRibbon {
    public static void main(String[] args) {
        // Function to find the maximum number of pieces that can be cut from a ribbon of given length

        // Take input as a list of integers, where the first integer represents the length of the ribbon
        Scanner sc = new Scanner(System.in);
        int[] arr = new int[4];
        for (int i = 0; i < 4; i++) {
            arr[i] = sc.nextInt();
        }

        // Assign the length of the ribbon to a variable
        int length = arr[0];

        // Sort the next three elements of the list in ascending order
        int[] sorted = new int[3];
        for (int i = 1; i < 4; i++) {
            sorted[i - 1] = arr[i];
        }
        Arrays.sort(sorted);

        // Check if the length of the ribbon is divisible by the first element of the sorted list
        if (length % sorted[0] == 0) {
            // If it is, print the number of pieces required and return
            System.out.println(length / sorted[0]);
            return;
        }

        // Initialize an answer variable to keep track of the maximum number of pieces that can be cut
        int ans = 0;

        // If the first two elements of the sorted list are equal
        if (sorted[0] == sorted[1]) {
            // Initialize a variable k to keep track of the number of pieces required
            int k = 0;

            // Loop to find the maximum number of pieces that can be cut from the ribbon
            for (int i = 0; i <= length / sorted[2]; i++) {
                // Check if the remaining length after subtracting i * sorted[2] is divisible by sorted[0]
                int check = length - i * sorted[2];
                if (check >= 0 && check % sorted[0] == 0) {
                    // If it is, update the answer and k
                    k = check / sorted[0];
                    ans = Math.max(ans, k + i);
                }
            }
        }

        // If the first two elements of the sorted list are not equal
        else {
            // Initialize a variable k to keep track of the number of pieces required
            int k = 0;

            // Double loop to find the maximum number of pieces that can be cut from the ribbon
            for (int i = 0; i <= length / sorted[2]; i++) {
                for (int j = 0; j <= length / sorted[1]; j++) {
                    // Check if the remaining length after subtracting i * sorted[2] and j * sorted[1] is divisible by sorted[0]
                    int check = length - i * sorted[2] - j * sorted[1];
                    if (check >= 0 && check % sorted[0] == 0) {
                        // If it is, update the answer and k
                        k = check / sorted[0];
                        ans = Math.max(ans, k + i + j);
                    }
                }
            }
        }

        // Print the final answer and return
        System.out.println(ans);
        return;
    }
}

