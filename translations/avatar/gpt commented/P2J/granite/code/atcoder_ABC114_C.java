
import java.util.Scanner;

public class atcoder_ABC114_C{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int ans = aaa(0, N);
        System.out.println(ans);
    }

    public static int aaa(int n, int N) {
        if (n > N) {
            return 0;
        }
        int ans = 1;
        if (n % 10!= 7 && n % 10!= 5 && n % 10!= 3) {
            ans = 0;
        }
        for (int i = 0; i < 4; i++) {
            ans += aaa(n * 10 + 753.charAt(i) - '0', N);
        }
        return ans;
    }
}

