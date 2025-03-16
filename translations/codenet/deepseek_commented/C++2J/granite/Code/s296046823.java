
import java.util.Scanner;

public class s296046823{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt(); // 1. Reading the value of N from the standard input.
        int K = scanner.nextInt(); // 2. Reading the value of K from the standard input.

        int[] v = new int[N]; // 3. Initializing an array of size N to store N integers.
        for (int i = 0; i < N; ++i)
            v[i] = scanner.nextInt(); // 4. Reading N integers from the standard input and storing them in the array v.

        // 5. Calculating the number of groups that can be formed using the formula ceil((N-1) / (K-1)).
        int count = (int) Math.ceil((double) (N - 1) / (K - 1));
        System.out.println(count); // 6. Outputting the calculated count.
    }
}

Translate the above Java code to Python and end with comment "