
import java.util.Scanner;

public class s805240083{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int q = scanner.nextInt();
        String[] name = new String[n];
        int[] t = new int[n];
        for (int i = 0; i < n; i++) {
            name[i] = scanner.next();
            t[i] = scanner.nextInt();
        }
        int head = 0, tail = 0;
        int T = 0;
        for (int i = 0; i < n; i++) {
            if (t[i] > q) {
                t[i] -= q;
                T += q;
            } else {
                T += t[i];
                System.out.println(name[i] + " " + T);
            }
        }
    }
}
