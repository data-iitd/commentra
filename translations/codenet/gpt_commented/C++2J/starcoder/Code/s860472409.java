import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Read the number of elements in the array
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        // Initialize an array of size N
        int[] A = new int[N];

        // Input the elements into the array
        for(int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }

        // Initialize index and counters
        int i = 0;
        int ans = 0;    // To store the final answer
        int count = 0;  // To count consecutive equal elements

        // Loop through the array until the second last element
        while(i + 1 < N) {
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
    }
}
