import java.util.Scanner;

public class InsertionSort {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int len = scanner.nextInt();
        int[] a = new int[101];

        for (int i = 0; i < len; i++) {
            a[i] = scanner.nextInt();
        }

        for (int j = 1; j < len; j++) {
            for (int i = 0; i < len; i++) {
                if (i != 0) {
                    System.out.print(" ");
                }
                System.out.print(a[i]);
            }
            System.out.println();

            int key = a[j];
            int i = j - 1;
            while (i >= 0 && a[i] > key) {
                a[i + 1] = a[i];
                i--;
            }
            a[i + 1] = key;
        }

        for (int i = 0; i < len; i++) {
            if (i != 0) {
                System.out.print(" ");
            }
            System.out.print(a[i]);
        }
        System.out.println();
        scanner.close();
    }
}
//<END-OF-CODE>
