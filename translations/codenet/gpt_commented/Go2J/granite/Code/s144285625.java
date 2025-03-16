
import java.util.Arrays;
import java.util.Scanner;

public class s144285625{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] ar = new int[3 * n];
        for (int i = 0; i < 3 * n; i++) {
            ar[i] = scanner.nextInt();
        }
        Arrays.sort(ar);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += ar[3 * n - (i + 1) * 2];
        }
        System.out.println(sum);
    }
}

// 