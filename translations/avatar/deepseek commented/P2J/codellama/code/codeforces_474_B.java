
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        arr[0] = 1;
        for (int i = 1; i < n; i++) {
            arr[i] = arr[i - 1] * 2;
        }
        int m = sc.nextInt();
        for (int i = 0; i < m; i++) {
            System.out.println(arr[sc.nextInt() - 1]);
        }
    }
}

