import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read n and k
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        
        // Read the array M
        int[] M = new int[n];
        for (int i = 0; i < n; i++) {
            M[i] = scanner.nextInt();
        }
        
        int m = 0;
        for (int j = 0; j < n; j++) {
            int p = -1;
            for (int i = 0; i < n; i++) {
                if (M[i] == 0) {
                    p = i;
                    System.out.print((p + 1) + " ");
                    break;
                }
            }
            if (p != -1) {
                for (int l = 0; l < p + 1 - k; l++) {
                    M[l]--;
                }
                M[p]--;
            }
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
