import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int T = scanner.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }
        
        int[] B = new int[N];
        int m = A[0];
        B[1] = A[1] - m;
        m = Math.min(m, A[1]);
        
        for (int i = 2; i < N; i++) {
            B[i] = A[i] - m;
            m = Math.min(m, A[i]);
        }
        
        int maxB = Arrays.stream(B).max().getAsInt();
        long count = Arrays.stream(B).filter(b -> b == maxB).count();
        System.out.println(count);
        
        scanner.close();
    }
}
// <END-OF-CODE>
