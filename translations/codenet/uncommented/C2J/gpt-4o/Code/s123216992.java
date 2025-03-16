import java.util.Scanner;

public class Main {
    public static void swap(int[] a, int[] b) {
        int tmp = a[0];
        a[0] = b[0];
        b[0] = tmp;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a, b;

        while (true) {
            a = scanner.nextInt();
            b = scanner.nextInt();
            if (a == 0 && b == 0) break;
            if (b < a) {
                int[] aRef = {a};
                int[] bRef = {b};
                swap(aRef, bRef);
                a = aRef[0];
                b = bRef[0];
            }
            System.out.println(a + " " + b);
        }
        scanner.close();
    }
}

// <END-OF-CODE>
