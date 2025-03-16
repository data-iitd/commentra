
import java.util.Scanner;

public class codeforces_412_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        String v = scanner.next();
        String[] d = {"LEFT", "RIGHT"};
        boolean f = k - 1 < n - k;
        int m = Math.min(k - 1, n - k);
        StringBuilder a = new StringBuilder();
        for (int i = 0; i < m; i++) {
            a.append(d[f? 0 : 1]).append("\n");
        }
        for (int i = f? v.length() - 1 : 0; f? i >= 0 : i < v.length(); i += f? -1 : 1) {
            a.append("PRINT ").append(v.charAt(i)).append("\n");
            a.append(d[f? 1 : 0]).append("\n");
        }
        System.out.println(a.substring(0, a.length() - 1));
    }
}
