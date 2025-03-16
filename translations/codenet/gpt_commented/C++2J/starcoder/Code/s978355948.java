import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Read the number of elements (N) and the threshold value (X)
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int X = sc.nextInt();
        
        // Initialize a vector L of size N to store the elements
        int[] L = new int[N];
        
        // Read N elements into the vector L
        for(int i = 0; i < N; i++)
            L[i] = sc.nextInt();
        
        // Initialize index variable and a variable to accumulate the sum
        int i;
        int d = 0;
        
        // Iterate through the elements of the vector L
        for(i = 0; i < N; i++) {
            // Accumulate the sum of elements
            d = d + L[i];
            
            // Check if the accumulated sum exceeds the threshold X
            if(d > X)
                break; // Exit the loop if the sum exceeds X
        }

        // Output the number of elements processed before exceeding X
        System.out.println(i + 1); // i + 1 because we want to count the number of elements
    }
}
