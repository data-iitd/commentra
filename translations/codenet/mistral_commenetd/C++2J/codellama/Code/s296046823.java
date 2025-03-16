import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize variables N and K with user input
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();

        // Create a vector 'v' of size N to store the input integers
        int[] v = new int[N];

        // Read N integers from the user and store them in the vector 'v'
        for (int i = 0; i < N; ++i) {
            v[i] = sc.nextInt();
        }

        // Calculate the number of subarrays of size K that can be formed from the vector 'v'
        int count = ((N - 1) + ((K - 1) - 1)) / (K - 1);

        // Output the result to the console
        System.out.println(count);
    }
}

