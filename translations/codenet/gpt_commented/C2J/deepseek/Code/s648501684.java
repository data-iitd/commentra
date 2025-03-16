public class Main {
    public static void main(String[] args) {
        // Declare variables to hold the number of elements (n), the threshold (k), and the number of queries (q)
        long n, k, q;
        
        // Read the values of n, k, and q from user input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextLong();
        k = scanner.nextLong();
        q = scanner.nextLong();
        
        // Initialize an array to count occurrences of each element, with size n
        int[] arr = new int[(int) n];
        
        // Process each query to count occurrences of the queried elements
        for(long i=0; i<q; i++) {
            long temp;
            // Read the queried element and increment its count in the array
            temp = scanner.nextLong();
            arr[(int) temp] += 1; // Increment the count for the queried element
        }
        
        // Check each element from 1 to n to see if its count exceeds the threshold (q - k)
        for(long i=0; i<n; i++) {
            // If the count of the element is greater than (q - k), print "Yes"
            if(arr[(int) i] > (q - k)) {
                System.out.println("Yes");
            } else {
                // Otherwise, print "No"
                System.out.println("No");
            }
        }
    }
}
