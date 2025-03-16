import java.util.Scanner;

public class SwapIntegers {
    public static void swap(int[] a, int[] b) {
        int tmp = a[0];
        a[0] = b[0];
        b[0] = tmp;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            if (a == 0 && b == 0) break;
            if (b < a) swap(new int[]{a}, new int[]{b});
            System.out.println(a + " " + b);
        }
        scanner.close();
    }
}
