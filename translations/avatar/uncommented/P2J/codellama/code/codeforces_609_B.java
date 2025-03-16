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
        int[] l = new int[n];
        for (int i = 0; i < n; i++) {
            if (l[arr[i]] == 0) {
                l[arr[i]] = 1;
            } else {
                l[arr[i]]++;
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (l[arr[i]] > 1) {
                res += n - i - l[arr[i]];
                l[arr[i]]--;
            } else {
                res += n - i - 1;
            }
        }
        System.out.println(res);
    }
}

