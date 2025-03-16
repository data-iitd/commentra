
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        if (arr[0] == arr[n - 1]) {
            System.out.println(0);
            return;
        }
        if (k == 1) {
            System.out.println(-1);
            return;
        }
        int target = arr[n - 1];
        int count = 0;
        for (int i = k - 1; i < n; i++) {
            if (arr[i] == target) {
                count++;
            } else {
                break;
            }
        }
        if (count == n - k + 1) {
            System.out.println(k - 1);
        } else {
            System.out.println(-1);
        }
    }
}

