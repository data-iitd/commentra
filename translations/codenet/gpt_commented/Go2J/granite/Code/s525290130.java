
import java.util.Scanner;

public class s525290130{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int q = sc.nextInt();
        for (int i = 0; i < q; i++) {
            int b = sc.nextInt();
            int e = sc.nextInt();
            reverse(a, b, e);
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                sb.append(" ");
            }
            sb.append(a[i]);
        }
        System.out.println(sb.toString());
    }

    public static void reverse(int[] a, int b, int e) {
        for (int i = b, j = e - 1; i < j; i++, j--) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
}

