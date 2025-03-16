
import java.util.Scanner;

public class s787964396{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n + 1];
        int[] b = new int[n + 1];
        int max = 0;
        for (int i = 0; i < n; i++) {
            a[i + 1] = scanner.nextInt();
            if (a[i + 1] > max) {
                max = a[i + 1];
            }
        }
        int[] c = new int[max + 1];
        for (int i = 0; i <= max; i++) {
            c[i] = 0;
        }
        for (int j = 0; j < n; j++) {
            c[a[j + 1]]++;
        }
        for (int i = 1; i <= max; i++) {
            c[i] += c[i - 1];
        }
        for (int j = n; 0 < j; j--) {
            b[c[a[j]]] = a[j];
            c[a[j]]--;
        }
        for (int i = 1; i < n + 1; i++) {
            System.out.print(b[i] + " ");
        }
        System.out.println();
    }
}

