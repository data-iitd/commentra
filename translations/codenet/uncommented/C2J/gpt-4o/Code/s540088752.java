import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int N = scanner.nextInt();
        
        int[] A = new int[N + 1];
        int[] B = new int[N];
        
        for (int i = 0; i < N + 1; i++) {
            A[i] = scanner.nextInt();
        }
        
        for (int i = 0; i < N; i++) {
            B[i] = scanner.nextInt();
        }
        
        long ans = 0;
        
        for (int i = 0; i < N; i++) {
            // site i
            if (A[i] >= B[i]) {
                ans += B[i];
                A[i] -= B[i];
                B[i] = 0;
            } else {
                ans += A[i];
                B[i] -= A[i];
                A[i] = 0;
            }

            // site i + 1
            if (A[i + 1] >= B[i]) {
                ans += B[i];
                A[i + 1] -= B[i];
                B[i] = 0;
            } else {
                ans += A[i + 1];
                B[i] -= A[i + 1];
                A[i + 1] = 0;
            }
        }
        
        System.out.println(ans);
        
        scanner.close();
    }
}

// <END-OF-CODE>
