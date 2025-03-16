import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int i_min = 0, min = 1000;
        int X, N;
        X = scanner.nextInt();
        N = scanner.nextInt();
        
        if (N == 0) {
            System.out.println(X);
            return;
        }
        
        int[] plus = new int[256];
        int[] minus = new int[256];
        
        for (int i = 0; i < 256; i++) {
            plus[i] = i;
            minus[i] = -1 * i;
        }
        
        for (int i = 0; i < N; i++) {
            int j = scanner.nextInt();
            plus[j] = 0;
        }
        
        for (int i = 255; i >= 0; i--) {
            if (plus[i] == 0 && i > 0) {
                continue;
            }
            int k = X - plus[i];
            if (k < 0) {
                k *= -1;
            }
            if (k <= min) {
                min = k;
                i_min = i;
            }
        }
        
        System.out.println(i_min);
        
        scanner.close();
    }
}
// <END-OF-CODE>
