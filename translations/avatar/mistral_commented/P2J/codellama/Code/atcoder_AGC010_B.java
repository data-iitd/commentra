import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
        }

        if (sum % (n * (n + 1) / 2)) {
            System.out.println("NO");
            return;
        }

        int k = sum / (n * (n + 1) / 2);

        a = addFirstElement(a);

        int[] diff = new int[n];
        for (int i = 0; i < n; i++) {
            diff[i] = (k - a[i] + a[i + 1]) % n;
        }

        if (sum(diff) != n) {
            System.out.println("NO");
            return;
        }

        for (int i = 0; i < n; i++) {
            diff[i] = (k - a[i] + a[i + 1]) / n;
        }

        if (sum(diff) != n) {
            System.out.println("NO");
            return;
        }

        System.out.println("YES");
    }

    public static int[] addFirstElement(int[] a) {
        int[] b = new int[a.length + 1];
        for (int i = 0; i < a.length; i++) {
            b[i] = a[i];
        }
        b[a.length] = a[0];
        return b;
    }

    public static int sum(int[] a) {
        int sum = 0;
        for (int i = 0; i < a.length; i++) {
            sum += a[i];
        }
        return sum;
    }
}

