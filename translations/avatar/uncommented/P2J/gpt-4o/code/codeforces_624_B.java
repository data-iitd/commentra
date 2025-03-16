import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        int[] a = new int[n];
        String[] input = scanner.nextLine().split(" ");
        
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(input[i]);
        }
        
        double pre = Double.POSITIVE_INFINITY;
        long ans = 0;
        
        Arrays.sort(a);
        for (int j = n - 1; j >= 0; j--) {
            ans += Math.max(0, Math.min(pre - 1, a[j]));
            pre = Math.max(0, Math.min(pre - 1, a[j]));
        }
        
        System.out.println(ans);
        scanner.close();
    }
}
//<END-OF-CODE>
