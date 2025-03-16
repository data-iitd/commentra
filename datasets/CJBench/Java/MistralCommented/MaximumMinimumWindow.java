
import java.util.Scanner;
import java.util.Stack;

public final class Main {
    private Main() {
        // Private constructor to prevent instantiation of the class
    }

    public static int[] calculateMaxOfMin(int[] arr, int n) {
        // Initialize a Stack and three arrays for storing left, right indices and answer
        Stack<Integer> s = new Stack<>();
        int[] left = new int[n];
        int[] right = new int[n];
        int[] ans = new int[n + 1];

        // Initialize left and right arrays with default values
        for (int i = 0; i < n; i++) {
            left[i] = -1;
            right[i] = n;
        }

        // Iterate through the input array using two nested loops
        for (int i = 0; i < n; i++) {
            // Use a Stack to keep track of the previous index with a smaller element
            while (!s.isEmpty() && arr[s.peek()] >= arr[i]) {
                // Pop the previous index from the Stack
                s.pop();
            }

            // If the Stack is not empty, update the left index for the current index
            if (!s.isEmpty()) {
                left[i] = s.peek();
            }

            // Push the current index into the Stack
            s.push(i);
        }

        // Clear the Stack for the next iteration
        s.clear();

        // Iterate through the input array again using a loop
        for (int i = n - 1; i >= 0; i--) {
            // Use a Stack to keep track of the next index with a smaller element
            while (!s.isEmpty() && arr[s.peek()] >= arr[i]) {
                // Pop the next index from the Stack
                s.pop();
            }

            // If the Stack is not empty, update the right index for the current index
            if (!s.isEmpty()) {
                right[i] = s.peek();
            }

            // Push the current index into the Stack
            s.push(i);
        }

        // Initialize an empty array to store the answers
        for (int i = 0; i < n; i++) {
            // Calculate the length of the current segment and update the answer accordingly
            int len = right[i] - left[i] - 1;
            ans[len] = Math.max(ans[len], arr[i]);
        }

        // Update the answers for the remaining indices
        for (int i = n - 1; i >= 1; i--) {
            ans[i] = Math.max(ans[i], ans[i + 1]);
        }

        // Return the calculated answers
        return ans;
    }

    public static void main(String[] args) {
        // Initialize a Scanner to read input from the standard input
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements in the input array
        int n = scanner.nextInt();

        // Allocate memory for the input array
        int[] arr = new int[n];

        // Read the elements of the input array
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        // Call the calculateMaxOfMin function and store the result in an array
        int[] result = calculateMaxOfMin(arr, n);

        // Print the results to the standard output
        for (int i = 1; i <= n; i++) {
            System.out.print(result[i] + " ");
        }

        // Close the Scanner
        scanner.close();
    }
}

