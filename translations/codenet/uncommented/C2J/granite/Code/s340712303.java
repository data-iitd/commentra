
import java.util.Scanner;

public class s340712303{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] math = new int[2001];
        math[0] = 1;
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            for (int j = 2000; j >= a; j--) {
                if (math[j - a] == 1) {
                    math[j] = 1;
                }
            }
        }
        int m = sc.nextInt();
        for (int i = 0; i < m; i++) {
            int ans = sc.nextInt();
            if (math[ans] == 1) {
                System.out.println("yes");
            } else {
                System.out.println("no");
            }
        }
    }
}
