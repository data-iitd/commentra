public class Main {
    public static void main(String[] args) {
        // Declare variables
        int N, ans, i, count;

        // Read the number of elements in the array
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        N = scanner.nextInt();

        // Initialize an array of size N
        int[] A = new int[N];

        // Input the elements into the array
        for(i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }

        // Initialize index and counters
        i = 0;
        ans = 0;    // To store the final answer
        count = 0;  // To count consecutive equal elements

        // Loop through the array until the second last element
        while(A[i + 1] != 0) {
            // Check if the current element is equal to the next element
            if(A[i] == A[i + 1]) {
                count++; // Increment count for consecutive elements
                
                // If count is odd, increment the answer
                if(count % 2 != 0)
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
