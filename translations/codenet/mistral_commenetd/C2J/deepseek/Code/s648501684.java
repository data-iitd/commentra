import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        long n = scanner.nextLong();
        long k = scanner.nextLong();
        long q = scanner.nextLong();

        int[] arr = new int[(int) n];

        for (int i = 0; i < q; i++) {
            int temp = scanner.nextInt();
            arr[temp - 1]++;
        }

        for (int i = 0; i < n; i++) {
            if (arr[i] > q - k) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        }

        scanner.close();
    }
}
