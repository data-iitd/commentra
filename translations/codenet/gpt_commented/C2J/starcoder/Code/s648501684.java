import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Declare variables to hold the number of elements (n), the threshold (k), and the number of queries (q)
        long n, k, q;
        
        // Read the values of n, k, and q from user input
        Scanner sc = new Scanner(System.in);
        n = sc.nextLong();
        k = sc.nextLong();
        q = sc.nextLong();
        
        // Initialize an array to count occurrences of each element, with size n
        int[] arr = new int[n+1];
        // Set all elements of the array to 0
        for(long i=0; i<=n; i++) {
            arr[i] = 0; // Initialize count for each element to zero
        }
        
        // Process each query to count occurrences of the queried elements
        for(long i=0; i<q; i++) {
            long temp;
            // Read the queried element and increment its count in the array
            temp = sc.nextLong();
            arr[temp] += 1; // Increment the count for the queried element
        }
        
        // Check each element from 1 to n to see if its count exceeds the threshold (q - k)
        for(long i=1; i<=n; i++) {
            // If the count of the element is greater than (q - k), print "Yes"
            if(arr[i] > (q - k)) {
                System.out.println("Yes");
            } else {
                // Otherwise, print "No"
                System.out.println("No");
            }
        }
    }
}
