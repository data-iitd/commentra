import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int[] vec = new int[n];
        
        for (int i = 0; i < n; i++) {
            vec[i] = scanner.nextInt();
        }
        
        Arrays.sort(vec);
        int ans = Integer.MAX_VALUE;
        
        for (int i = 0; i + k - 1 < n; i++) {
            int diff = vec[i + k - 1] - vec[i];
            if (diff < ans) {
                ans = diff;
            }
        }
        
        System.out.println(ans);
        scanner.close();
    }
}

// <END-OF-CODE>
