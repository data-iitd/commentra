import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements N
        int N = scanner.nextInt();
        
        // Create an array A to store N integers
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            // Read each integer and store it in array A
            A[i] = scanner.nextInt();
        }
        
        // Sort the array A in ascending order
        Arrays.sort(A);
        
        // Initialize the answer variable to store the result
        int ans = 0;
        for (int i = 1; i < N; i++) {
            // Calculate the sum of differences between consecutive elements
            ans += A[i] - A[i - 1];
        }
        
        // Print the result
        System.out.println(ans);
    }
}
