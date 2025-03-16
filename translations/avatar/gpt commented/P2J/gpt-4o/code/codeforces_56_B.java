import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements in the list
        int N = scanner.nextInt();
        
        // Read the list of integers from input
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }
        
        // Initialize minimum and maximum indices for the range of elements that are out of place
        int mn = N + 1, mx = -1;

        // Iterate through the list to find the first and last indices where the element is not in its correct position
        for (int i = 0; i < N; i++) {
            // Check if the current index + 1 does not match the value at that index
            if ((i + 1) != A[i]) {
                // Update the minimum index if the current index is less than the current minimum
                mn = Math.min(mn, i);
                // Update the maximum index if the current index is greater than the current maximum
                mx = Math.max(mx, i);
            }
        }

        // If no elements were out of place, output '0 0'
        if (mx == -1) {
            System.out.println("0 0");
        } else {
            // Reverse the subarray from mn to mx
            int[] reversedSubarray = new int[mx - mn + 1];
            for (int i = 0; i < reversedSubarray.length; i++) {
                reversedSubarray[i] = A[mx - i];
            }
            
            // Create a new array with the reversed subarray
            int[] newArray = new int[N];
            for (int i = 0; i < mn; i++) {
                newArray[i] = A[i];
            }
            for (int i = 0; i < reversedSubarray.length; i++) {
                newArray[mn + i] = reversedSubarray[i];
            }
            for (int i = mx + 1; i < N; i++) {
                newArray[i] = A[i];
            }

            // Check if the modified list is sorted
            if (Arrays.equals(newArray, Arrays.stream(newArray).sorted().toArray())) {
                // If sorted, print the 1-based indices of the range that was reversed
                System.out.println((mn + 1) + " " + (mx + 1));
            } else {
                // If not sorted, output '0 0'
                System.out.println("0 0");
            }
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
