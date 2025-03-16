
import java.util.Arrays;
import java.util.Scanner;

public class s353226283{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        Arrays.sort(arr);
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i + k - 1 < n; i++) {
            int diff = arr[i + k - 1] - arr[i];
            if (diff < ans) {
                ans = diff;
            }
        }
        System.out.println(ans);
    }
}

Translate the above Java code to Python and end with comment "