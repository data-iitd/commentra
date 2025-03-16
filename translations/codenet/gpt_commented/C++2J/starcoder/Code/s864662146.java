import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Read the number of elements from user input
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        
        // Declare an array A of size N to hold the elements
        int[] A = new int[N];
        
        // Read N elements into the array A
        for (int i = 0; i < N; i++) A[i] = sc.nextInt();

        // Initialize m and M to the first element of the array A
        int m = A[0];
        int M = A[0];
        
        // Iterate through the array to find the minimum and maximum values
        for (int i = 0; i < N; i++) {
            // Update m if the current element is less than the current minimum
            if (A[i] < m) m = A[i];
            
            // Update M if the current element is greater than the current maximum
            if (A[i] > M) M = A[i];
        }

        // Output the difference between the maximum and minimum values
        System.out.println(M - m);
    }
}
