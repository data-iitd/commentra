import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        System.out.println(aaa(0));
    }

    public static int aaa(int n) {
        if (n > N) {
            return 0;
        }
        int ans = n == 0 || (n % 10 == 7 || n % 10 == 5 || n % 10 == 3) ? 1 : 0;
        ans += aaa(n * 10 + 7);
        ans += aaa(n * 10 + 5);
        ans += aaa(n * 10 + 3);
        return ans;
    }
}
