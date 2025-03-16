
import java.util.Scanner;

public class s296046823{
    public static void main(String[] args) {
        // Declare variables N and K to hold the number of elements and the divisor respectively
        int N, K;
        
        // Create a Scanner object to read input from standard input
        Scanner scanner = new Scanner(System.in);
        
        // Read the values of N and K from standard input
        N = scanner.nextInt();
        K = scanner.nextInt();

        // Initialize an array of size N to store the input elements
        int[] v = new int[N];
        
        // Read N integers from standard input and store them in the array v
        for (int i = 0; i < N; ++i)
            v[i] = scanner.nextInt();

        // Calculate the number of groups needed based on the formula ceil((N-1) / (K-1))
        // This is done using integer arithmetic to avoid floating-point operations
        int count = ((N - 1) + ((K - 1) - 1)) / (K - 1);
        
        // Output the calculated count of groups
        System.out.println(count);
        
        // Close the Scanner object to release system resources
        scanner.close();
    }
}
