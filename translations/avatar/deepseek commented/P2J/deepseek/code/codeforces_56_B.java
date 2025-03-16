import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();  // Read the integer input N
        int[] A = new int[N];  // Read the list of integers A
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }

        // Initialize variables to track the minimum and maximum indices where the condition is true
        int mn = N + 1, mx = -1;

        // Iterate over the range of N to find the indices where the condition is true
        for (int i = 0; i < N; i++) {
            if ((i + 1 != A[i])) {
                mn = Math.min(mn, i);  // Update mn if a smaller index is found
                mx = Math.max(mx, i);  // Update mx if a larger index is found
            }
        }

        // Check if no indices satisfy the condition
        if (mx == -1) {
            System.out.println("0 0");  // Print '0 0' if no indices satisfy the condition
        } else {
            // Reverse the sublist from index mn to mx + 1 and update A
            int[] temp = new int[N];
            for (int i = 0; i < N; i++) {
                if (i < mn) {
                    temp[i] = A[i];
                } else if (i >= mn && i <= mx) {
                    temp[i] = A[mn + mx - i];
                } else {
                    temp[i] = A[i];
                }
            }
            A = temp;

            // Check if the list A is sorted
            boolean isSorted = true;
            for (int i = 0; i < N - 1; i++) {
                if (A[i] > A[i + 1]) {
                    isSorted = false;
                    break;
                }
            }
            if (isSorted) {
                System.out.println((mn + 1) + " " + (mx + 1));  // Print the indices if A is sorted
            } else {
                System.out.println("0 0");  // Print '0 0' if A is not sorted
            }
        }
    }
}
