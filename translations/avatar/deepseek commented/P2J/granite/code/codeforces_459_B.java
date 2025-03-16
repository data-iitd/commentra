
import java.util.Arrays;
import java.util.Scanner;

public class codeforces_459_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] l1 = new int[n];
        for (int i = 0; i < n; i++) {
            l1[i] = scanner.nextInt();
        }
        Arrays.sort(l1);
        int a = l1[n - 1];
        int b = l1[0];
        if (a == b) {
            System.out.println(a - b + " " + (long) n * (n - 1) / 2);
        } else {
            int ac = 0, bc = 0;
            for (int i = 0; i < n; i++) {
                if (l1[i] == a) {
                    ac++;
                }
                if (l1[i] == b) {
                    bc++;
                }
            }
            System.out.println(a - b + " " + ac * bc);
        }
    }
}
