import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int[] h = new int[n];
        
        for (int i = 0; i < n; i++) {
            h[i] = scanner.nextInt();
        }
        
        Map<Integer, Object> counter = new HashMap<>();
        
        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            if (h[a - 1] < h[b - 1]) {
                counter.put(a, new Object());
            } else if (h[a - 1] > h[b - 1]) {
                counter.put(b, new Object());
            } else {
                counter.put(a, new Object());
                counter.put(b, new Object());
            }
        }
        
        System.out.println(n - counter.size());
        scanner.close();
    }
}
// <END-OF-CODE>
