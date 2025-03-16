
import java.util.Arrays;
import java.util.Scanner;

public class atcoder_ABC171_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        Arrays.sort(a);
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += a[i];
        }
        System.out.println(sum);
    }
}
