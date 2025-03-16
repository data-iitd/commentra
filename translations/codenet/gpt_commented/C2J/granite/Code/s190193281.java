
import java.util.Scanner;

public class s190193281{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();  // Read the number of elements in the sorted array S
        int[] S = new int[n];  // Declare and initialize the sorted array S
        for (int i = 0; i < n; i++) {
            S[i] = scanner.nextInt();  // Read the elements into the sorted array S
        }
        int q = scanner.nextInt();  // Read the number of queries
        int[] T = new int[q];  // Declare and initialize the query array T
        for (int i = 0; i < q; i++) {
            T[i] = scanner.nextInt();  // Read the query elements into array T
        }
        int c = 0;  // Declare and initialize the count of found elements
        for (int i = 0; i < q; i++) {
            if (binarySearch(S, T[i])) c++;  // If the element is found, increment the count
        }
        System.out.println(c);  // Output the total count of found elements
        scanner.close();  // Close the scanner
    }

    // Function to perform binary search on the sorted array S
    public static boolean binarySearch(int[] S, int key) {
        int left = 0, right = S.length, mid;  // Initialize left and right pointers for the search range
        while (left < right) {  // Continue searching while the range is valid
            mid = (left + right) / 2;  // Calculate the middle index
            if (S[mid] == key) return true;  // If the key is found, return true
            else if (key < S[mid]) right = mid;  // Narrow the search to the left half
            else left = mid + 1;  // Narrow the search to the right half
        }
        return false;  // If the key is not found, return false
    }
}
