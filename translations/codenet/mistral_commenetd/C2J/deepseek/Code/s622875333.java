import java.util.Scanner;

public class ArrayRotation {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, r, i, j, p, c;
        int[] a = new int[100];
        int[] b = new int[100];

        while (true) {
            System.out.print("Enter the number of elements in array a: ");
            n = scanner.nextInt();
            System.out.print("Enter the number of rotations: ");
            r = scanner.nextInt();

            if (n == 0 && r == 0) {
                break;
            }

            for (i = 0; i < n; i++) {
                a[i] = n - i;
            }

            for (i = 0; i < r; i++) {
                System.out.println("\nBefore rotation " + (i + 1) + ":");
                for (j = 0; j < n; j++) {
                    System.out.print(a[j] + " ");
                }
                System.out.println();

                for (j = 0; j < n; j++) {
                    b[j] = a[j];
                }

                System.out.print("Enter the number of elements to be rotated: ");
                c = scanner.nextInt();
                System.out.print("Enter the position: ");
                p = scanner.nextInt();

                for (j = 0; j < c; j++) {
                    b[j] = b[j + 1];
                }

                for (j = 0; j < c; j++) {
                    a[j] = b[p - 1 + j];
                }

                for (j = c; j < n; j++) {
                    a[j] = b[j - c];
                }

                System.out.println("\nAfter rotation " + (i + 1) + ":");
                for (j = 0; j < n; j++) {
                    System.out.print(a[j] + " ");
                }
                System.out.println();
            }

            System.out.println("\nThe first element of the final array is: " + a[0]);
        }
    }
}
