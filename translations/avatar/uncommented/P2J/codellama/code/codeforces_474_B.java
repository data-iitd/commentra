import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        int r = 1;
        for (int i = 0; i < n; i++) {
            arr[i] = r;
            r++;
        }
        int m = sc.nextInt();
        for (int i = 0; i < m; i++) {
            System.out.println(arr[sc.nextInt() - 1]);
        }
    }
}

