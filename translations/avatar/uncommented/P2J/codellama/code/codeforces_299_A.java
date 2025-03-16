import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        Arrays.sort(arr);
        int first = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] % first != 0) {
                System.out.println(first);
                return;
            }
        }
        System.out.println(-1);
    }
}

