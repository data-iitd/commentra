
import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Declare variables to store the input values
        long n, k, q;
        
        // Read three long integers from the standard input
        Scanner sc = new Scanner(System.in);
        n = sc.nextLong();
        k = sc.nextLong();
        q = sc.nextLong();
        
        // Declare an array of size n initialized to 0
        int[] arr = new int[n];
        for(long i=0; i<=n; i++) {
            arr[i] = 0; // Initialize each element to 0
        }
        
        // Read q integers and increment the corresponding index in the array arr
        for(long i=0; i<q; i++) {
            long temp;
            temp = sc.nextLong();
            arr[temp] += 1;
        }
        
        // Check if the value at each index in arr is greater than q-k
        for(long i=1; i<=n; i++) {
            if(arr[i]>(q-k)) {
                System.out.println("Yes"); // Print "Yes" if the condition is met
            } else {
                System.out.println("No"); // Print "No" otherwise
            }
        }
    }
}

