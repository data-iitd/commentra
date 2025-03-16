
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        int[] freq = new int[m];
        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (freq[arr[i]] > 1) {
                res += n - i - freq[arr[i]];
                freq[arr[i]]--;
            } else {
                res += n - i - 1;
            }
        }
        System.out.println(res);
    }
}

