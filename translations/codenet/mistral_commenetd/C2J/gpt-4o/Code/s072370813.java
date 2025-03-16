import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables
        Scanner scanner = new Scanner(System.in);
        int N;                  // Number of elements in the array
        long long sum = 0;      // Sum of all elements in the array
        long long wa = 0;       // Sum of all indices from 1 to N
        int ans = 0;            // Answer flag
        int shou;               // Quotient of sum and wa

        // Read input
        N = scanner.nextInt();
        int[] A = new int[N];   // Array to store input elements
        int[] sa = new int[N];  // Array to store differences between adjacent elements

        // Read N integers into the array A
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
            // Add current element to sum
            sum += A[i];
            // Add current index to wa
            wa += (i + 1);
        }

        // Check if sum is divisible by wa
        if (sum % wa != 0) {
            ans = 0;
        } else {
            // Calculate quotient of sum and wa
            shou = (int)(sum / wa);
            // Calculate differences between adjacent elements and store in array sa
            for (int i = 0; i < N; i++) {
                sa[i] = A[(i + 1) % N] - A[i] - shou;
            }

            // Check if any difference is less than or equal to 0 and divisible by N
            for (int i = 0; i < N - 1; i++) {
                if (sa[i] <= 0 && sa[i] % N == 0) {
                    ans = 1;
                } else {
                    ans = 0;
                    break;
                }
            }
        }

        // Print answer
        if (ans == 1) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }

        scanner.close();
    }
}
// <END-OF-CODE>
