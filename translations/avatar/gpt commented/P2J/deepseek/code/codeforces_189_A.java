import java.util.Arrays;
import java.util.Scanner;

public class CutRibbon {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input and convert it into an array of integers
        int[] arr = Arrays.stream(scanner.nextLine().split(" "))
                          .mapToInt(Integer::parseInt)
                          .toArray();
        
        // The first element is the total length of the ribbon
        int length = arr[0];
        
        // Sort the next three elements (the lengths of the pieces) in ascending order
        Arrays.sort(arr, 1, 4);
        
        // If the total length is divisible by the smallest piece length, print the maximum number of pieces
        if (length % arr[1] == 0) {
            System.out.println(length / arr[1]);
            return;
        }
        
        // Initialize the answer variable to keep track of the maximum pieces
        int ans = 0;
        
        // Case when the two smallest piece lengths are equal
        if (arr[1] == arr[2]) {
            int k = 0;
            // Iterate through the number of the largest pieces that can fit into the ribbon
            for (int i = 0; i <= length / arr[3]; i++) {
                // Calculate the remaining length after using i pieces of the largest size
                int check = length - i * arr[3];
                // Check if the remaining length can be completely divided by the smallest piece length
                if (check >= 0 && check % arr[1] == 0) {
                    k = check / arr[1];
                    // Update the maximum pieces found
                    ans = Math.max(ans, k + i);
                }
            }
        } else {
            // Case when the two smallest piece lengths are different
            int k = 0;
            // Iterate through the number of the largest pieces that can fit into the ribbon
            for (int i = 0; i <= length / arr[3]; i++) {
                // Iterate through the number of the second largest pieces that can fit into the ribbon
                for (int j = 0; j <= length / arr[2]; j++) {
                    // Calculate the remaining length after using i pieces of the largest size and j pieces of the second largest size
                    int check = length - i * arr[3] - j * arr[2];
                    // Check if the remaining length can be completely divided by the smallest piece length
                    if (check >= 0 && check % arr[1] == 0) {
                        k = check / arr[1];
                        // Update the maximum pieces found
                        ans = Math.max(ans, k + i + j);
                    }
                }
            }
        }
        
        // Print the maximum number of pieces that can be obtained
        System.out.println(ans);
    }
}
