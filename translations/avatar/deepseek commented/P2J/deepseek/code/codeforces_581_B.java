import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Step 1: Take the number of elements in the array as input
        int n = scanner.nextInt();

        // Step 2: Take a space-separated string of integers as input, convert them to a list of integers, and slice it to the first n elements
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        // Step 3: Initialize an array `ans` of zeros with the same length as the input array
        int[] ans = new int[n];

        // Step 4: Initialize `mx` to the last element of the array `arr`
        int mx = arr[n - 1];

        // Step 5: Iterate from the second last element to the first element of the array `arr` in reverse order
        for (int i = n - 2; i >= 0; i--) {
            // Step 6: Calculate the value `max(0, mx - arr[i] + 1)` and assign it to the corresponding position in the `ans` array
            ans[i] = Math.max(0, mx - arr[i] + 1);
            
            // Step 7: If the current element is greater than `mx`, update `mx` with the current element
            if (arr[i] > mx) {
                mx = arr[i];
            }
        }

        // Step 8: Print the elements of the `ans` array
        for (int i = 0; i < n; i++) {
            System.out.print(ans[i] + " ");
        }
    }
}

