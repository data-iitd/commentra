import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables N and K to hold the number of elements and the divisor respectively
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();

        // Initialize an array of size N to store the input elements
        int[] v = new int[N];

        // Read N integers from standard input and store them in the array v
        for (int i = 0; i < N; i++) {
            v[i] = scanner.nextInt();
        }

        // Calculate the number of groups needed based on the formula ceil((N-1) / (K-1))
        // This is done using integer arithmetic to avoid floating-point operations
        int count = ((N - 1) + (K - 2)) / (K - 1);

        // Output the calculated count of groups
        System.out.println(count);
        
        scanner.close();
    }
}

// <END-OF-CODE>
