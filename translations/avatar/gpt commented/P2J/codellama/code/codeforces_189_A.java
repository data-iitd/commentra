import java.util.Scanner;

public class RibbonCutting {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the command line
        Scanner scanner = new Scanner(System.in);
        
        // Read input and convert it into a list of integers
        int[] arr = new int[4];
        for (int i = 0; i < 4; i++) {
            arr[i] = scanner.nextInt();
        }
        
        // The first element is the total length of the ribbon
        int length = arr[0];
        
        // Sort the next three elements (the lengths of the pieces) in ascending order
        int[] sortedArr = new int[3];
        for (int i = 0; i < 3; i++) {
            sortedArr[i] = arr[i + 1];
        }
        Arrays.sort(sortedArr);
        
        // If the total length is divisible by the smallest piece length, print the maximum number of pieces
        if (length % sortedArr[0] == 0) {
            System.out.println(length / sortedArr[0]);
            return;
        }
        
        // Initialize the answer variable to keep track of the maximum pieces
        int ans = 0;
        
        // Case when the two smallest piece lengths are equal
        if (sortedArr[0] == sortedArr[1]) {
            int k = 0;
            // Iterate through the number of the largest pieces that can fit into the ribbon
            for (int i = 0; i <= length / sortedArr[2]; i++) {
                // Calculate the remaining length after using i pieces of the largest size
                int check = length - i * sortedArr[2];
                // Check if the remaining length can be completely divided by the smallest piece length
                if (check >= 0 && check % sortedArr[0] == 0) {
                    k = check / sortedArr[0];
                    // Update the maximum pieces found
                    ans = Math.max(ans, k + i);
                }
            }
        } else {
            // Case when the two smallest piece lengths are different
            int k = 0;
            // Iterate through the number of the largest pieces that can fit into the ribbon
            for (int i = 0; i <= length / sortedArr[2]; i++) {
                // Iterate through the number of the second largest pieces that can fit into the ribbon
                for (int j = 0; j <= length / sortedArr[1]; j++) {
                    // Calculate the remaining length after using i pieces of the largest size and j pieces of the second largest size
                    int check = length - i * sortedArr[2] - j * sortedArr[1];
                    // Check if the remaining length can be completely divided by the smallest piece length
                    if (check >= 0 && check % sortedArr[0] == 0) {
                        k = check / sortedArr[0];
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
