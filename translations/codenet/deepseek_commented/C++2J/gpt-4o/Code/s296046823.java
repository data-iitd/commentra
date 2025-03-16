import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int N = scanner.nextInt(); // 1. Reading the value of N from the standard input.
        int K = scanner.nextInt(); // 1. Reading the value of K from the standard input.

        ArrayList<Integer> v = new ArrayList<>(N); // 2. Initializing an ArrayList to store N integers.
        for (int i = 0; i < N; i++) {
            v.add(scanner.nextInt()); // 3. Reading N integers from the standard input and storing them in the ArrayList v.
        }

        // 4. Calculating the number of groups that can be formed using the formula ceil((N-1) / (K-1)).
        int count = (N - 1 + (K - 2)) / (K - 1);
        System.out.println(count); // 5. Outputting the calculated count.
        
        scanner.close();
    }
}

// <END-OF-CODE>
