
import java.util.Scanner;

public class s784517449{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); // Read the number of elements in the array
        int[] A = new int[n]; // Create an array A to hold the elements
        for (int i = 0; i < n; i++) {
            A[i] = sc.nextInt(); // Read the elements into the array A
        }
        int q = sc.nextInt(); // Read the number of queries
        int sum = 0; // Initialize the sum counter
        for (int i = 0; i < q; i++) {
            int k = sc.nextInt(); // Read the key to search for
            if (binarySearch(A, k)) { // Perform binary search for the key
                sum++; // Increment the sum if the key is found
            }
        }
        System.out.println(sum); // Output the total number of keys found in the array
        sc.close();
    }

    // Binary search function
    public static boolean binarySearch(int[] A, int key) {
        int left = 0; // Initialize the left boundary of the search range
        int right = A.length; // Initialize the right boundary of the search range
        while (left < right) {
            int mid = (left + right) / 2; // Calculate the midpoint index during the search
            if (key == A[mid]) {
                return true; // If the key is found, return true
            } else if (key > A[mid]) {
                left = mid + 1; // If the key is greater, search in the right half
            } else {
                right = mid; // If the key is smaller, search in the left half
            }
        }
        return false; // If the key is not found, return false
    }
}

