import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        long[] A = new long[N];
        
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextLong();
        }

        long answer = 0;
        // Calculate the maximum absolute difference between any two elements in the array
        for (int i = 0; i < N - 1; i++) {
            for (int j = i + 1; j < N; j++) {
                long diff = Math.abs(A[i] - A[j]);
                answer = Math.max(answer, diff);
            }
        }
        // Output the result
        System.out.println(answer);
        scanner.close();
    }
}
// <END-OF-CODE>
