import java.util.Scanner;
import java.util.Stack;

public final class Main {
    private Main() {
    }

    // Calculate the maximum of minimums for each window size
    public static int[] calculateMaxOfMin(int[] arr, int n) {
        // Stack to keep track of indices
        Stack<Integer> s = new Stack<>();
        // Arrays to store the nearest smaller element to the left and right
        int[] left = new int[n];
        int[] right = new int[n];
        // Array to store the maximum of minimums for different window sizes
        int[] ans = new int[n + 1];

        // Setting initial values for left and right arrays
        for (int i = 0; i < n; i++) {
            left[i] = -1;
            right[i] = n;
        }

        // Filling the left array with nearest smaller element to the left
        for (int i = 0; i < n; i++) {
            while (!s.isEmpty() && arr[s.peek()] >= arr[i]) {
                s.pop();
            }
            if (!s.isEmpty()) {
                left[i] = s.peek();
            }
            s.push(i);
        }

        // Clearing the stack for reuse
        s.clear();

        // Filling the right array with nearest smaller element to the right
        for (int i = n - 1; i >= 0; i--) {
            while (!s.isEmpty() && arr[s.peek()] >= arr[i]) {
                s.pop();
            }
            if (!s.isEmpty()) {
                right[i] = s.peek();
            }
            s.push(i);
        }

        // Updating the ans array with the maximum value for each window size
        for (int i = 0; i < n; i++) {
            int len = right[i] - left[i] - 1;
            ans[len] = Math.max(ans[len], arr[i]);
        }

        // Ensuring the ans array is correctly populated
        for (int i = n - 1; i >= 1; i--) {
            ans[i] = Math.max(ans[i], ans[i + 1]);
        }

        return ans;
    }

    // Main method to read input and print results
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        int[] result = calculateMaxOfMin(arr, n);
        for (int i = 1; i <= n; i++) {
            System.out.print(result[i] + " ");
        }
        scanner.close();
    }
}
