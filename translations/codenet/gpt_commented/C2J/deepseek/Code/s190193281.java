public class BinarySearch {
    static final int N = 1000000;  // Maximum size for the array S
    static final int Q = 50000;    // Maximum size for the array T

    static int n, S[] = new int[N];  // Declare variables: n for the number of elements, S for the sorted array
    static int T[] = new int[Q];     // Declare array T for the query array

    // Function to perform binary search on the sorted array S
    static int binarySearch(int key) {
        int left = 0, right = n, mid;  // Initialize left and right pointers for the search range
        while(left < right) {  // Continue searching while the range is valid
            mid = (left + right) / 2;  // Calculate the middle index
            if(S[mid] == key) return 1;  // If the key is found, return 1
            else if(key < S[mid]) right = mid;  // Narrow the search to the left half
            else left = mid + 1;  // Narrow the search to the right half
        }
        return 0;  // If the key is not found, return 0
    }

    public static void main(String[] args) {
        int i, q, c = 0;  // Declare variables: i for loops, q for number of queries, c for count of found keys
        
        // Read the number of elements in the sorted array S
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();
        
        // Read the elements into the sorted array S
        for(i = 0; i < n; i++) {
            S[i] = scanner.nextInt();
        }
        
        // Read the number of queries
        q = scanner.nextInt();
        
        // Process each query to check if it exists in the sorted array S
        for(i = 0; i < q; i++) {
            T[i] = scanner.nextInt();  // Read the query element into array T
            if(binarySearch(T[i]) == 1) c++;  // If the element is found, increment the count
        }
        
        // Output the total count of found elements
        System.out.println(c);
    }
}
