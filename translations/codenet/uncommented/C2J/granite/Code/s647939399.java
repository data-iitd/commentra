
import java.util.Scanner;

public class s647939399{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char m;
        int a, b, c[] = new int[256], i, j;
        for (i = 0; i > -1; i++) {
            a = sc.nextInt();
            m = sc.next().charAt(0);
            b = sc.nextInt();
            if (m == '?') {
                break;
            }
            if (m == '+') {
                c[i] = a + b;
            }
            if (m == '-') {
                c[i] = a - b;
            }
            if (m == '*') {
                c[i] = a * b;
            }
            if (m == '/') {
                c[i] = a / b;
            }
        }
        for (j = 0; j < i; j++) {
            System.out.println(c[j]);
        }
    }
}
