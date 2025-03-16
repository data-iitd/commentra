import java.util.Arrays;
import java.util.Scanner;

public class RibbonCutting {

    public static void cutRibbon() {
        Scanner scanner = new Scanner(System.in);
        
        // Read input and convert it into an array of integers
        String input = scanner.nextLine();
        String[] inputArray = input.split(" ");
        int length = Integer.parseInt(inputArray[0]);
        
        // Store the lengths of the pieces in an array
        int[] arr = new int[3];
        for (int i = 0; i < 3; i++) {
            arr[i] = Integer.parseInt(inputArray[i + 1]);
        }
        
        // Sort the lengths of the pieces in ascending order
        Arrays.sort(arr);
        
        // If the total length is divisible by the smallest piece length, print the maximum number of pieces
        if (length % arr[0] == 0) {
            System.out.println(length / arr[0]);
            return;
        }
        
        // Initialize the answer variable to keep track of the maximum pieces
        int ans = 0;
        
        // Case when the two smallest piece lengths are equal
        if (arr[0] == arr[1]) {
            for (int i = 0; i <= length / arr[2]; i++) {
                // Calculate the remaining length after using i pieces of the largest size
                int check = length - i * arr[2];
                // Check if the remaining length can be completely divided by the smallest piece length
                if (check >= 0 && check % arr[0] == 0) {
                    int k = check / arr[0];
                    // Update the maximum pieces found
                    ans = Math.max(ans, k + i);
                }
            }
        } else {
            // Case when the two smallest piece lengths are different
            for (int i = 0; i <= length / arr[2]; i++) {
                for (int j = 0; j <= length / arr[1]; j++) {
                    // Calculate the remaining length after using i pieces of the largest size and j pieces of the second largest size
                    int check = length - i * arr[2] - j * arr[1];
                    // Check if the remaining length can be completely divided by the smallest piece length
                    if (check >= 0 && check % arr[0] == 0) {
                        int k = check / arr[0];
                        // Update the maximum pieces found
                        ans = Math.max(ans, k + i + j);
                    }
                }
            }
        }
        
        // Print the maximum number of pieces that can be obtained
        System.out.println(ans);
    }

    public static void main(String[] args) {
        cutRibbon();
    }
}

// <END-OF-CODE>
