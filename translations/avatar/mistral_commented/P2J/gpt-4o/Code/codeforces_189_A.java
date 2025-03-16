import java.util.Arrays;
import java.util.Scanner;

public class RibbonCutting {

    public static void cutRibbon() {
        // Function to find the maximum number of pieces that can be cut from a ribbon of given length

        // Take input as a list of integers, where the first integer represents the length of the ribbon
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().split(" ");
        int length = Integer.parseInt(input[0]);

        // Assign the next three elements of the list to an array
        int[] arr = new int[3];
        for (int i = 0; i < 3; i++) {
            arr[i] = Integer.parseInt(input[i + 1]);
        }

        // Sort the array in ascending order
        Arrays.sort(arr);

        // Check if the length of the ribbon is divisible by the first element of the sorted array
        if (length % arr[0] == 0) {
            // If it is, print the number of pieces required and return
            System.out.println(length / arr[0]);
            return;
        }

        // Initialize an answer variable to keep track of the maximum number of pieces that can be cut
        int ans = 0;

        // If the first two elements of the sorted array are equal
        if (arr[0] == arr[1]) {
            // Initialize a variable k to keep track of the number of pieces required
            int k = 0;

            // Loop to find the maximum number of pieces that can be cut from the ribbon
            for (int i = 0; i <= length / arr[2]; i++) {
                // Check if the remaining length after subtracting i * arr[2] is divisible by arr[0]
                int check = length - i * arr[2];
                if (check >= 0 && check % arr[0] == 0) {
                    // If it is, update the answer and k
                    k = check / arr[0];
                    ans = Math.max(ans, k + i);
                }
            }
        } else {
            // If the first two elements of the sorted array are not equal
            int k = 0;

            // Double loop to find the maximum number of pieces that can be cut from the ribbon
            for (int i = 0; i <= length / arr[2]; i++) {
                for (int j = 0; j <= length / arr[1]; j++) {
                    // Check if the remaining length after subtracting i * arr[2] and j * arr[1] is divisible by arr[0]
                    int check = length - i * arr[2] - j * arr[1];
                    if (check >= 0 && check % arr[0] == 0) {
                        // If it is, update the answer and k
                        k = check / arr[0];
                        ans = Math.max(ans, k + i + j);
                    }
                }
            }
        }

        // Print the final answer and return
        System.out.println(ans);
    }

    public static void main(String[] args) {
        cutRibbon();
    }
}

// <END-OF-CODE>
