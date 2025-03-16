
import java.util.Scanner;

public class s978355948{
    public static void main(String[] args) {
        // Declare variables for the number of elements (N) and the threshold value (X)
        int N, X;
        
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Read the values of N and X from standard input
        N = scanner.nextInt();
        X = scanner.nextInt();
        
        // Initialize an array L of size N to store the elements
        int[] L = new int[N];
        
        // Read N elements into the array L
        for(int i = 0; i < N; i++)
            L[i] = scanner.nextInt();
        
        // Initialize index variable and a variable to accumulate the sum
        int i;
        int d = 0;
        
        // Iterate through the elements of the array L
        for(i = 0; i < N; i++) {
            // Accumulate the sum of elements
            d = d + L[i];
            
            // Check if the accumulated sum exceeds the threshold X
            if(d > X)
                break; // Exit the loop if the sum exceeds X
        }

        // Output the number of elements processed before exceeding X
        System.out.println(i + 1); // i + 1 because we want to count the number of elements
        
        // Close the Scanner object to release system resources
        scanner.close();
    }
}
