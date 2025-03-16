import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // The code reads an integer N.
        int N = scanner.nextInt();
        
        // It then creates a list A where each element is the product of an integer input and N plus its index i, for i in range(N).
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt() * N + i;
        }
        
        // The list A is sorted.
        Arrays.sort(A);
        
        // A counter cnt is initialized to 0.
        int cnt = 0;
        
        // The code then iterates over the elements of A, checking if the remainder when divided by N, when divided by 2, matches the remainder of the index i when divided by 2.
        for (int i = 0; i < N; i++) {
            int d = (A[i] % N) % 2;
            if (d % 2 != i % 2) {
                cnt++;
            }
        }
        
        // Finally, the code prints the result of cnt divided by 2.
        System.out.println(cnt / 2);
        
        scanner.close();
    }
}
// <END-OF-CODE>
