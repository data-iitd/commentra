public class Main {
    public static void main(String[] args) {
        // Initialize variables N and K with user input
        int N, K;
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        N = scanner.nextInt();
        K = scanner.nextInt();

        // Create a vector 'v' of size N to store the input integers
        int[] v = new int[N];

        // Read N integers from the user and store them in the array 'v'
        for (int i = 0; i < N; ++i) {
            v[i] = scanner.nextInt();
        }

        // Calculate the number of subarrays of size K that can be formed from the array 'v'
        int count = ((N - 1) + ((K - 1) - 1)) / (K - 1);

        // Output the result to the console
        System.out.println(count);
    }
}
