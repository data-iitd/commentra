import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        // Initialize variables N and K with user input
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();

        // Create an ArrayList 'v' to store the input integers
        ArrayList<Integer> v = new ArrayList<>(N);

        // Read N integers from the user and store them in the ArrayList 'v'
        for (int i = 0; i < N; ++i) {
            v.add(scanner.nextInt());
        }

        // Calculate the number of subarrays of size K that can be formed from the ArrayList 'v'
        int count = ((N - 1) + ((K - 1) - 1)) / (K - 1);

        // Output the result to the console
        System.out.println(count);
        
        scanner.close();
    }
}

// <END-OF-CODE>
