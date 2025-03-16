import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        int sum = 0;
        int odd = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 == 1) {
                odd++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 == 0) {
                sum += arr[i];
            } else if (odd > 1) {
                sum += arr[i];
                odd--;
            }
        }
        System.out.println(sum);
    }
}

