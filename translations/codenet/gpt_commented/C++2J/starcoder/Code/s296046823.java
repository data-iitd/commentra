import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Read the values of N and K from standard input
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();

        // Initialize a vector of size N to store the input elements
        int[] v = new int[N];
        
        // Read N integers from standard input and store them in the vector v
        for (int i = 0; i < N; ++i)
            v[i] = sc.nextInt();

        // Calculate the number of groups needed based on the formula ceil((N-1) / (K-1))
        // This is done using integer arithmetic to avoid floating-point operations
        int count = ((N - 1) + ((K - 1) - 1)) / (K - 1);
        
        // Output the calculated count of groups
        System.out.println(count);
    }
}
