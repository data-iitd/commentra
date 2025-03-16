import java.util.Scanner;

public class Main {
    static final int M = 1010;
    static char[] a = new char[M];
    static char[] b = new char[M];
    static int n, m, ans = M + 10;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        String inputA = scanner.next();
        a = inputA.toCharArray();
        n = inputA.length();
        
        String inputB = scanner.next();
        b = inputB.toCharArray();
        m = inputB.length();
        
        for (int i = 0; i + m <= n; i++) {
            int sum = 0;
            for (int j = 0; j < m; j++) {
                if (a[i + j] != b[j]) {
                    sum++;
                }
            }
            ans = Math.min(ans, sum);
        }
        
        System.out.println(ans);
        scanner.close();
    }
}

// <END-OF-CODE>
