import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long sum = 0;
        int[] a = new int[n];

        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        for (int i = 1; i < n; i++) {
            if (a[i - 1] > a[i]) {
                sum += a[i - 1] - a[i];
                a[i] = a[i - 1];
            }
        }

        System.out.println(sum);
        scanner.close();
    }
}

// <END-OF-CODE>
