

import java.util.Scanner;

public class codeforces_412_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        scanner.nextLine();
        String v = scanner.nextLine();
        String[] d = {"LEFT", "RIGHT"};
        boolean f = k - 1 < n - k;
        int m = Math.min(k - 1, n - k);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < m; i++) {
            sb.append(d[f? 0 : 1]).append("\n");
        }
        for (int i = 0; i < v.length(); i++) {
            sb.append("PRINT ").append(v.charAt(i)).append("\n");
            sb.append(d[f? 1 : 0]).append("\n");
        }
        System.out.println(sb.toString());
    }
}

Translate the above Java code to C++ and end with comment "