
import java.util.Scanner;

public class s754383079{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.nextLine();
        String b = sc.nextLine();
        int n = a.length();
        int m = b.length();
        int ans = m + 10;
        for (int i = 0; i <= n - m; i++) {
            int sum = 0;
            for (int j = 0; j < m; j++) {
                if (a.charAt(i + j)!= b.charAt(j)) {
                    sum++;
                }
            }
            ans = Math.min(ans, sum);
        }
        System.out.println(ans);
    }
}

