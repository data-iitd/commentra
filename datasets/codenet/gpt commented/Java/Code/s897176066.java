import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);
        
        // Read the number of elements N
        int N = sc.nextInt();
        
        // Initialize an array A to hold N long integers
        long A[] = new long[N];
        
        // Read N long integers into the array A
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextLong();
        }
        
        // Sort the array A to facilitate duplicate checking
        Arrays.sort(A);
        
        // Check for duplicates in the sorted array
        for (int j = 1; j < N; j++) {
            // If a duplicate is found, print "NO" and exit the program
            if (A[j] == A[j - 1]) {
                System.out.println("NO");
                System.exit(0);
            }
        }
        
        // If no duplicates are found, print "YES"
        System.out.println("YES");
    }
}
