
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long k = sc.nextLong();
        long q = sc.nextLong();

        int[] arr = new int[(int) n + 1];
        for (int i = 0; i <= n; i++) {
            arr[i] = 0;
        }

        for (int i = 0; i < q; i++) {
            int temp = sc.nextInt();
            arr[temp] += 1;
        }

        for (int i = 1; i <= n; i++) {
            if (arr[i] > (q - k)) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        }
    }
}

