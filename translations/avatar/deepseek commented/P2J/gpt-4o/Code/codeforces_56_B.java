import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int N = scanner.nextInt();  // Read the integer input N
        int[] A = new int[N];  // Initialize the array A
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();  // Read the list of integers A
        }

        // Initialize variables to track the minimum and maximum indices where the condition is true
        int mn = N + 1, mx = -1;

        // Iterate over the range of N to find the indices where the condition is true
        for (int i = 0; i < N; i++) {
            if ((i + 1) != A[i]) {
                mn = Math.min(mn, i);  // Update mn if a smaller index is found
                mx = Math.max(mx, i);  // Update mx if a larger index is found
            }
        }

        // Check if no indices satisfy the condition
        if (mx == -1) {
            System.out.println("0 0");  // Print '0 0' if no indices satisfy the condition
        } else {
            // Reverse the sublist from index mn to mx + 1 and update A
            int[] reversedSublist = new int[mx - mn + 1];
            for (int i = 0; i < reversedSublist.length; i++) {
                reversedSublist[i] = A[mx - i];  // Fill reversed sublist
            }
            int[] newA = new int[N];
            System.arraycopy(A, 0, newA, 0, mn);  // Copy elements before mn
            System.arraycopy(reversedSublist, 0, newA, mn, reversedSublist.length);  // Insert reversed sublist
            System.arraycopy(A, mx + 1, newA, mn + reversedSublist.length, N - (mx + 1));  // Copy elements after mx

            // Check if the list A is sorted
            boolean isSorted = true;
            for (int i = 1; i < newA.length; i++) {
                if (newA[i] < newA[i - 1]) {
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

        scanner.close();
    }
}
// <END-OF-CODE>
