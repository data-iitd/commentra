
import java.util.*;

public class s860472409{
    public static void main(String[] args) {
        // Declare variables
        Scanner sc = new Scanner(System.in);
        int N, ans, i, count;

        // Read the number of elements in the array
        N = sc.nextInt();

        // Initialize an array of size N
        int A[] = new int[N];

        // Input the elements into the array
        for(i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }

        // Initialize index and counters
        i = 0;
        ans = 0;    // To store the final answer
        count = 0;  // To count consecutive equal elements

        // Loop through the array until the second last element
        while(A[i + 1]!= null) {
            // Check if the current element is equal to the next element
            if(A[i] == A[i + 1]) {
                count++; // Increment count for consecutive elements
                
                // If count is odd, increment the answer
                if(count % 2!= 0)
                    ans++;
            } else {
                // Reset count if elements are not equal
                count = 0;
            }
            i++; // Move to the next element
        }

        // Output the final answer
        System.out.println(ans);
        sc.close(); // Close the scanner
    }
}
