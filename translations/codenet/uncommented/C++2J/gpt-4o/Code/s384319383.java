import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long[] cnt = new long[26];
        char[] s = new char[n];

        for (int i = 0; i < n; i++) {
            s[i] = scanner.next().charAt(0);
            cnt[s[i] - 'a']++;
        }

        long ans = cnt[0];
        for (int i = 1; i < 26; i++) {
            ans *= cnt[i];
            ans %= 1000000007; // MOD
        }

        System.out.println(ans - 1);
        scanner.close();
    }
}
// <END-OF-CODE>
